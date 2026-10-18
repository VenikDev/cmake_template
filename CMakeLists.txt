cmake_minimum_required(VERSION 3.31)
project(cmake_template LANGUAGES CXX)

# Dependencies and compiler tools are provided by the Pixi environment.
message(STATUS "Pixi environment: $ENV{CONDA_PREFIX}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



enable_testing()

add_subdirectory(packages/main)
add_subdirectory(packages/tests)
add_subdirectory(packages/benchmarks)
