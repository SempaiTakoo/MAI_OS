cmake_minimum_required(VERSION 3.20)

project(MAI_OS)

enable_testing()

include(FindThreads)

add_subdirectory(lab1)

add_subdirectory(lab2)

add_subdirectory(tests)
