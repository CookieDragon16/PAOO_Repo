cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(test VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(HEADERS
    Player.hpp
    Character.hpp
    Archer.hpp
    Swordsman.hpp
    Enemy.hpp
)

set(SOURCES
    Player.cpp
    Archer.cpp
    Swordsman.cpp
    Enemy.cpp
)

add_library(Character ${HEADERS} ${SOURCES})
