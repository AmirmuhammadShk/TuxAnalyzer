#pragma once

#include <string>
#include <vector>
#include <optional>

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

private:
    static std::optional<std::vector<SearchResult>> search_in_file(
        const std::string& file,
        const std::string& keyword
    );
};