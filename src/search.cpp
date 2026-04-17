#include "search.hpp"

#include <fstream>
#include <thread>
#include <mutex>

std::optional<std::vector<SearchResult>> SearchEngine::search_in_file(
    const std::string& file,
    const std::string& keyword
) {
    std::ifstream in(file);

    if (!in.is_open()) {
        return std::nullopt;
    }

    std::vector<SearchResult> local_results;

    std::string line;
    int line_number = 0;

    while (std::getline(in, line)) {
        ++line_number;

        if (line.find(keyword) != std::string::npos) {
            local_results.push_back({file, line_number, line});
        }
    }

    return local_results;
}

std::vector<SearchResult> SearchEngine::search(
    const std::vector<std::string>& files,
    const std::string& keyword
) {
    std::vector<SearchResult> results;
    std::mutex mtx;

    std::vector<std::thread> threads;

    for (const auto& file : files) {
        threads.emplace_back([&results, &mtx, file, keyword]() {
            auto res = search_in_file(file, keyword);

            if (res) {
                std::lock_guard<std::mutex> lock(mtx);
                results.insert(results.end(), res->begin(), res->end());
            }
        });
    }

    for (auto& t : threads) {
        t.join();
    }

    return results;
}