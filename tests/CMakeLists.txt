cmake_minimum_required(VERSION 3.20)

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)



add_executable(
    lab1_test
    lab1_test.cpp
    ../lab1/include/utils.h
    ../lab1/src/utils.cpp
    ../lab1/include/parent.h
    ../lab1/src/parent.cpp
)

target_include_directories(lab1_test PRIVATE ../lab1/include)
target_link_libraries(lab1_test PRIVATE GTest::GTest)


add_executable(
    lab2_test lab2_test.cpp
    ../lab2/src/kMeans.cpp
    ../lab2/include/kMeans.hpp
)

target_link_libraries(lab2_test PRIVATE GTest::GTest)
target_include_directories(lab2_test PRIVATE ../lab2/include)
