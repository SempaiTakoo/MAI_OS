cmake_minimum_required(VERSION 3.20)
project(lab1)

add_executable(
    lab1
    src/main.cpp
    include/parent.h
    include/utils.h
    src/parent.cpp
    src/utils.cpp
)

add_executable(
    child1
    src/child1.cpp
)

add_executable(
    child2
    src/child2.cpp
)

target_include_directories(lab1 PRIVATE include)

target_compile_features(lab1 PRIVATE cxx_std_20)
target_compile_options(lab1 PRIVATE -Wall -Wextra -Wpedantic)