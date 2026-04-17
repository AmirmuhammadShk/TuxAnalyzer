#pragma once

#include <string>
#include <vector>

enum class CommandType {
    Find,
    Stats,
    Largest,
    Version,
    Unknown
};

struct Command {
    CommandType type{CommandType::Unknown};
    std::vector<std::string> args;
};