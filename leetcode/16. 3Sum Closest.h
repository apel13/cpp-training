//
// Created by apel on 31.12.2020.
//

#ifndef CPP_TRAINING_16_3SUM_CLOSEST_H
#define CPP_TRAINING_16_3SUM_CLOSEST_H

// problem:
// https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());

        int min = INT_MAX;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < target) {
                    ++l;
                    if (target - sum < abs(min))
                        min = target - sum;
                }
                else {
                    --r;
                    if (sum - target < abs(min))
                        min = target - sum;
                }
            }
        }
        return target - min;
    }
};

#endif //CPP_TRAINING_16_3SUM_CLOSEST_H
