cmake_minimum_required(VERSION 3.29)
project(07___Structure_Enum)

set(CMAKE_CXX_STANDARD 14)

include_directories(..)

add_executable(07___Structure_Enum
    "01-04 - Date_Personne.cpp"
        date.cpp
        date.h
        personne.cpp
        personne.h)
