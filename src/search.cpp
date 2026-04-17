#include "search.hpp"

#include <fstream>
#include <iostream>

std::vector<SearchResult> SearchEngine::search(
    const std::vector<std::string>& files,
    const std::string& keyword
) {
    std::vector<SearchResult> results;

    for (const auto& file : files) {
        std::ifstream in(file);

        if (!in.is_open()) {
            continue;
        }

        std::string line;
        int line_number = 0;

        while (std::getline(in, line)) {
            ++line_number;

            if (line.find(keyword) != std::string::npos) {
                results.push_back({file, line_number, line});
            }
        }
    }

    return results;
}