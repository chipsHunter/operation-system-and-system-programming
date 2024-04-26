cmake_minimum_required(VERSION 3.27)
project(parent C)

set(CMAKE_C_STANDARD 99)
set(CUSTOM_COMPILE_FLAGS "-W -Wall -Wno-unused-parameter -Wno-unused-variable -std=c11 -pedantic")
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} ${CUSTOM_COMPILE_FLAGS}")

add_executable(parent main.c
        parent.c
        parent.h)
