#pragma once

#include <string>
#include <vector>

struct ProjectStats {
    size_t file_count;
    size_t total_lines;
};

class StatsEngine {
public:
    static ProjectStats compute(const std::vector<std::string>& files);

    static std::vector<std::pair<std::string, size_t>> largest_files(
        const std::vector<std::string>& files,
        size_t top_n = 5
    );
};