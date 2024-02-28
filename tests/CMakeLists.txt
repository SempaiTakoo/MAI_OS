cmake_minimum_required(VERSION 3.20)
project(tests)

add_executable(
    lab1_test
    lab1_test.cpp
    ../lab1/include/utils.h
    ../lab1/src/utils.cpp
    ../lab1/include/parent.h
    ../lab1/src/parent.cpp
)

find_package(GTest REQUIRED)

target_include_directories(lab1_test PRIVATE ../lab1/include)
target_link_libraries(lab1_test PRIVATE GTest::GTest)

target_compile_features(lab1_test PRIVATE cxx_std_20)
target_compile_options(lab1_test PRIVATE -Wall -Wextra -Wpedantic)

enable_testing()
add_test(lab1_test lab1_test)