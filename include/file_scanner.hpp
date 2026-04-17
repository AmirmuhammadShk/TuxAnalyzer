#pragma once

#include <string>
#include <vector>

class FileScanner {
public:
    // Scan directory and return all file paths
    static std::vector<std::string> scan(const std::string& path);
};