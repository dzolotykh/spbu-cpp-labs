cmake_minimum_required(VERSION 3.26)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES
        "entity/.cpp"
        "inventory/.cpp"
        "items/.cpp"
        "game/.cpp"
        "team/.cpp"
)

include_directories(
        .
        inventory
        entity
        items
        team
        game
)

add_executable(main main.cpp ${SOURCES})