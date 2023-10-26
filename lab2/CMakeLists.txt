cmake_minimum_required(VERSION 3.26)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2 main.cpp
        inventory/Inventory.h
        inventory/Inventory.cpp
        items/Item.cpp
        entity/Entity.h
        entity/Entity.cpp
        entity/hero/Pudge.cpp
        entity/creep/Creep.h
        entity/creep/FractionCreep.h
        entity/hero/Hero.cpp
        entity/hero/Hero.h
        items/Tango.h
        items/Tango.cpp
        items/FaerieFire.cpp
        items/HeartOfTarrasque.h
        items/HeartOfTarrasque.cpp
        entity/creep/FractionCreep.cpp
        entity/creep/Creep.cpp
        team/Team.h
        team/Team.cpp
        game/Game.h
        game/Game.cpp
        entity/hero/Sniper.h
        entity/hero/Sniper.cpp
        entity/hero/Axe.h
        entity/hero/Axe.cpp
        entity/hero/Dazzle.cpp
        entity/hero/Puck.h
        entity/hero/Puck.cpp
        entity/hero/Alchemist.h
        entity/hero/Alchemist.cpp
        entity/creep/NeuralCreep.h
        entity/creep/NeuralCreep.cpp

)
