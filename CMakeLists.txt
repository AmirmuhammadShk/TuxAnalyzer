cmake_minimum_required(VERSION 3.16)

project(TuxAnalyzer VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(tuxanalyzer
    src/main.cpp
    src/cli.cpp
    src/command.cpp
    src/file_scanner.cpp
    src/search.cpp
    src/stats.cpp
)
target_include_directories(tuxanalyzer PRIVATE include)