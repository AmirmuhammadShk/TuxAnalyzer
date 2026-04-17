#include "stats.hpp"

#include <fstream>
#include <algorithm>

ProjectStats StatsEngine::compute(const std::vector<std::string>& files) {
    ProjectStats stats{0, 0};

    stats.file_count = files.size();

    for (const auto& file : files) {
        std::ifstream in(file);

        if (!in.is_open()) {
            continue;
        }

        std::string line;
        while (std::getline(in, line)) {
            stats.total_lines++;
        }
    }

    return stats;
}

std::vector<std::pair<std::string, size_t>> StatsEngine::largest_files(
    const std::vector<std::string>& files,
    size_t top_n
) {
    std::vector<std::pair<std::string, size_t>> file_sizes;

    for (const auto& file : files) {
        std::ifstream in(file);

        if (!in.is_open()) {
            continue;
        }

        size_t lines = 0;
        std::string line;

        while (std::getline(in, line)) {
            lines++;
        }

        file_sizes.push_back({file, lines});
    }

    std::sort(file_sizes.begin(), file_sizes.end(),
        [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

    if (file_sizes.size() > top_n) {
        file_sizes.resize(top_n);
    }

    return file_sizes;
}