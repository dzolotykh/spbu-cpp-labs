cmake_minimum_required(VERSION 3.22)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE sources
        "src/*.cpp" "src/*.h"
)

add_executable(main ${sources})