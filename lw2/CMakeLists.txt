cmake_minimum_required(VERSION 3.6)
project(lw2)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp TriangleSum/TriangleSum.h TriangleSum/TriangleSum.cpp)
add_executable(lw2 ${SOURCE_FILES})

project(lw2_testing)

set(SOURCE_FILES testing.cpp TriangleSum/TriangleSum.h TriangleSum/TriangleSum.cpp)
add_executable(lw2_testing ${SOURCE_FILES})