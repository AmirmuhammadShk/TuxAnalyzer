#include "cli.hpp"

#include <iostream>
#include <string>

Command parse_command(int argc, char* argv[]) {
    Command command{};

    if (argc < 2) {
        return command;
    }

    std::string cmd = argv[1];

    if (cmd == "find") {
        command.type = CommandType::Find;
    } else if (cmd == "stats") {
        command.type = CommandType::Stats;
    } else if (cmd == "largest") {
        command.type = CommandType::Largest;
    } else if (cmd == "version") {
        command.type = CommandType::Version;
    } else {
        command.type = CommandType::Unknown;
    }

    for (int i = 2; i < argc; ++i) {
        command.args.push_back(argv[i]);
    }

    return command;
}

void print_help() {
    std::cout << "TuxAnalyzer - Modern C++ Project Analyzer\n";
    std::cout << "Usage:\n";
    std::cout << "  tuxanalyzer find <keyword> <path>\n";
    std::cout << "  tuxanalyzer stats <path>\n";
    std::cout << "  tuxanalyzer largest <path>\n";
    std::cout << "  tuxanalyzer version\n";
}