//
// Created by apel on 28.12.2020.
//

#ifndef CPP_TRAINING_128_LONGEST_CONSECUTIVE_SEQUENCE_H
#define CPP_TRAINING_128_LONGEST_CONSECUTIVE_SEQUENCE_H

// problem:
// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    // o(n)
    int longestConsecutive(vector<int> &nums) {
        size_t n = nums.size(); if(n < 2) return n;
        std::unordered_set<int> m(nums.begin(), nums.end());
        int res = 0;
        int cur = 0;
        for(auto &el : m) {
            if (m.count(el - 1) == 0) {
                int cur_num = el + 1;
                while (m.count(cur_num++)) {}
                res = std::max(res, cur_num- el -1);
            }
        }
        return res;
    }
};

#endif //CPP_TRAINING_128_LONGEST_CONSECUTIVE_SEQUENCE_H
