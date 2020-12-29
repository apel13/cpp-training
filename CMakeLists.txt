cmake_minimum_required(VERSION 3.17)
project(cpp_training)

set(CMAKE_CXX_STANDARD 17)

include_directories(leetcode)

add_executable(cpp_training
        "leetcode/1472. Design-browser-history.h"
        main.cpp "leetcode/687. Longest Univalue Path.h" "leetcode/1641. Count Sorted Vowel Strings.h" "leetcode/1277. Count Square Submatrices with All Ones.h" "leetcode/1463. Cherry Pickup II.h" "leetcode/304. Range Sum Query 2D - Immutable.h" "leetcode/5. Longest Palindromic Substring.h" "leetcode/32. Longest Valid Parentheses.h" "leetcode/1314. Matrix Block Sum.h" "leetcode/128. Longest Consecutive Sequence.h" "leetcode/239. Sliding Window Maximum.h" "leetcode/1402. Reducing Dishes.h" "leetcode/76. Minimum Window Substring.h" "leetcode/1696. Jump Game VI.h" "leetcode/149. Max Points on a Line.h" "concurrency/1114. Print in Order.h")
