#include "cli.hpp"
#include "file_scanner.hpp"
#include "search.hpp"
#include "stats.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
    Command command = parse_command(argc, argv);

    switch (command.type) {

        case CommandType::Find: {
            if (command.args.size() < 2) {
                std::cout << "[ERROR] Usage: find <keyword> <path>\n";
                return 1;
            }

            std::string keyword = command.args[0];
            std::string path = command.args[1];

            auto files = FileScanner::scan(path);
            auto results = SearchEngine::search(files, keyword);

            std::cout << "[INFO] Found " << results.size() << " matches\n";

            for (const auto& r : results) {
                std::cout << r.file << ":" << r.line_number
                          << " -> " << r.line << "\n";
            }

            break;
        }

        case CommandType::Stats: {
            std::string path = command.args.empty() ? "." : command.args[0];

            auto files = FileScanner::scan(path);
            auto stats = StatsEngine::compute(files);

            std::cout << "[STATS]\n";
            std::cout << "Files: " << stats.file_count << "\n";
            std::cout << "Total lines: " << stats.total_lines << "\n";

            break;
        }

        case CommandType::Largest: {
            std::string path = command.args.empty() ? "." : command.args[0];

            auto files = FileScanner::scan(path);
            auto largest = StatsEngine::largest_files(files);

            std::cout << "[LARGEST FILES]\n";

            for (const auto& [file, lines] : largest) {
                std::cout << file << " -> " << lines << " lines\n";
            }

            break;
        }

        case CommandType::Unknown:
        default:
            print_help();
            return 1;
    }

    return 0;
}