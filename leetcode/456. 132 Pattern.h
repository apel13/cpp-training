//
// Created by apel on 31.12.2020.
//

#ifndef CPP_TRAINING_456_132_PATTERN_H
#define CPP_TRAINING_456_132_PATTERN_H

// problem:
// https://leetcode.com/problems/132-pattern/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size(); if (n < 3) return false;
        std::vector<int> min_left(n); min_left[0] = nums[0];
        for (int i = 1; i < n; ++i)
            min_left[i] = std::min(min_left[i-1], nums[i]);

        int k = n;
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] != min_left[i]) {
                while (k < n && nums[k] <= min_left[i]) k++;
                if (k < n && nums[k] < nums[i]) return true;
                nums[--k] = nums[i];
            }
        }
        return false;
    }
};

#endif //CPP_TRAINING_456_132_PATTERN_H
