cmake_minimum_required(VERSION 3.26)
project(Wentor)

set(CMAKE_CXX_STANDARD 23)

add_executable(Wentor main.cpp
        Queue.cpp
        Queue.h
)
