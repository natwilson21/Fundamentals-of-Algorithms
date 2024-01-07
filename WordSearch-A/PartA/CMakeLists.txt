cmake_minimum_required(VERSION 3.20)
project(PartA)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PartA
        dictionary.cpp
        dictionary.h
        main.cpp
        Grid.cpp
        Grid.h)