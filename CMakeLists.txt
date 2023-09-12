cmake_minimum_required(VERSION 3.26)
project(lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab1 vector.cpp
        vector.h
        complex_numbers.cpp
        complex_numbers.h
        main.cpp)
