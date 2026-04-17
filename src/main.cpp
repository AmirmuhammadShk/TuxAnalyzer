#include "cli.hpp"
#include "file_scanner.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    Command command = parse_command(argc, argv);

    switch (command.type) {
        case CommandType::Find:
            std::cout << "[INFO] Find command selected\n";
            break;

        case CommandType::Stats:
            std::cout << "[INFO] Stats command selected\n";
            break;

        case CommandType::Largest: {
            if (command.args.empty()) {
                std::cout << "[ERROR] Path required\n";
                return 1;
            }

            std::string path = command.args.back();

            auto files = FileScanner::scan(path);

            std::cout << "[INFO] Found " << files.size() << " files\n";

            // print first few files (for test)
            for (size_t i = 0; i < std::min(files.size(), size_t(5)); ++i) {
                std::cout << files[i] << "\n";
            }

            break;
        }


        case CommandType::Unknown:
        default:
            print_help();
            return 1;
    }

    if (!command.args.empty()) {
        std::cout << "Arguments:\n";
        for (const auto& arg : command.args) {
            std::cout << "  - " << arg << '\n';
        }
    }

    return 0;
}