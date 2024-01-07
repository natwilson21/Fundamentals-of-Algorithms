cmake_minimum_required(VERSION 3.20)
project(macwil-2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(macwil-2
        Card.cpp
        Card.h
        main.cpp
        Deck.cpp
        Deck.h
        Node.h)