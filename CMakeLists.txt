cmake_minimum_required(VERSION 3.17)
project(cpp_training)

set(CMAKE_CXX_STANDARD 14)

include_directories(leetcode)

add_executable(cpp_training
        "leetcode/1472. Design-browser-history.h"
        main.cpp)
