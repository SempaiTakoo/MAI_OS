set(CMAKE_C_STANDARD 17)

add_executable(lab2
        main.cpp
        include/kMeans.hpp
        src/kMeans.cpp)

target_include_directories(lab2 PRIVATE include)