cmake_minimum_required(VERSION 3.6)
project(task2)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp FenvikTree/Helpers.h)
add_executable(task1 ${SOURCE_FILES})