//
// Created by apel on 11.12.2020.
//

#ifndef CPP_TRAINING_41_FIRST_MISSING_POSITIVE_H
#define CPP_TRAINING_41_FIRST_MISSING_POSITIVE_H

// problem:
// https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        while (i < n) {
            if (1 <= nums[i] && nums[i] <= n) {
                if (nums[nums[i] - 1] != nums[i])
                    std::swap(nums[nums[i] - 1], nums[i]);
                else
                    ++i;
            }
            else
                ++i;
        }
        for (i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                if (i == 0) return 1;
                return nums[i - 1] + 1;
            }
        }
        return n + 1;
    }
};

#endif //CPP_TRAINING_41_FIRST_MISSING_POSITIVE_H
