#pragma once

#include <string>
#include <vector>

struct SearchResult {
    std::string file;
    int line_number;
    std::string line;
};

class SearchEngine {
public:
    static std::vector<SearchResult> search(
        const std::vector<std::string>& files,
        const std::string& keyword
    );
};