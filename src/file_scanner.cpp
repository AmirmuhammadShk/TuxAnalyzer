#include "file_scanner.hpp"

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

std::vector<std::string> FileScanner::scan(const std::string& path) {
    std::vector<std::string> files;

    try {
        if (!fs::exists(path)) {
            std::cerr << "[ERROR] Path does not exist: " << path << "\n";
            return files;
        }

        if (!fs::is_directory(path)) {
            std::cerr << "[ERROR] Not a directory: " << path << "\n";
            return files;
        }

        for (const auto& entry : fs::recursive_directory_iterator(path)) {
            if (entry.is_regular_file()) {
                files.push_back(entry.path().string());
            }
        }

    } catch (const fs::filesystem_error& e) {
        std::cerr << "[ERROR] Filesystem error: " << e.what() << "\n";
    }

    return files;
}