cmake_minimum_required(VERSION 3.20)
project(macwil-3-PartB)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(macwil-3-PartB
        dictionary.h
        Grid.h
        dictionary.cpp
        Grid.cpp
        main.cpp)