cmake_minimum_required(VERSION 3.20)
project(macwil-1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(macwil-1
        Code.cpp
        Code.h
        main.cpp
        Mastermind.cpp
        Mastermind.h
        Response.cpp
        Response.h)
