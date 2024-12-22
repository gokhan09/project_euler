cmake_minimum_required(VERSION 3.29)
project(project_euler)

set(CMAKE_CXX_STANDARD 26)

add_executable(project_euler main.cpp
        questions_11_20/programs11_20.cpp
        questions_11_20/programs11_20.h
        questions_21_30/programs_21_30.cpp
        questions_21_30/programs_21_30.h
)
