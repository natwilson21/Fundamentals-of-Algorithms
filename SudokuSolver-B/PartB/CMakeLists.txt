cmake_minimum_required(VERSION 3.20)
project(PartB)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PartB
        matrix.h
        except.h
        board.h
        board.cpp
        main.cpp)