cmake_minimum_required(VERSION 3.17)
project(cpp_training)

set(CMAKE_CXX_STANDARD 17)

include_directories(leetcode)

add_executable(cpp_training
        main.cpp "leetcode/1326. Minimum Number of Taps to Open to Water a Garden.h" "leetcode/695. Max Area of Island.h" "leetcode/200. Number of Islands.h" "leetcode/130. Surrounded Regions.h" "leetcode/1162. As Far from Land as Possible.h")
