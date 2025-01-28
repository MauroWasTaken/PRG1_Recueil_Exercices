cmake_minimum_required(VERSION 3.25)
project(exos9)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconversion -Wall -Wextra -pedantic -std=c++23")

# Project files
add_executable(exos9
        02-07.cpp
)