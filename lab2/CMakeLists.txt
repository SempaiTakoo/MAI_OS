cmake_minimum_required(VERSION 3.20)
project(lab2)

add_executable(
    lab2
    src/main.cpp
)

target_include_directories(lab2 PRIVATE include)

target_compile_features(lab2 PRIVATE cxx_std_20)
target_compile_options(lab2 PRIVATE -Wall -Wextra -Wpedantic)
