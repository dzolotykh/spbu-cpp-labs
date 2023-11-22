cmake_minimum_required(VERSION 3.26)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp
        inventory/Inventory.h
        inventory/Inventory.cpp
        entity/Entity.h
        entity/Entity.cpp
        entity/hero/Hero.cpp
        entity/hero/Hero.h
        items/Tango.h
        items/Tango.cpp
        items/FaerieFire.cpp
        team/Team.h
        team/Team.cpp
        game/Game.h
        game/Game.cpp
        entity/hero/Axe.h
        entity/hero/Axe.cpp
        entity/hero/Dazzle.cpp
        entity/hero/Alchemist.h
        entity/hero/Alchemist.cpp
)
