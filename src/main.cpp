#include "cli.hpp"

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

        case CommandType::Largest:
            std::cout << "[INFO] Largest command selected\n";
            break;

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