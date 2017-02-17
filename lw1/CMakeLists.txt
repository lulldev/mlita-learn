cmake_minimum_required(VERSION 3.6)
project(lw1)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp BracketHandler/BracketHandler.cpp BracketHandler/BracketHandler.h)
add_executable(lw1 ${SOURCE_FILES} BracketHandler/BracketHandler.cpp BracketHandler/BracketHandler.h)