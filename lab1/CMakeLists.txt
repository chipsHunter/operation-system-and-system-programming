cmake_minimum_required(VERSION 3.27)
project(laba1 C)

set(CMAKE_C_STANDARD 99)

add_executable(dirwalk main.c
        functions.h
        functions.c)
