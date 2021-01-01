//
// Created by apel on 31.12.2020.
//

#ifndef CPP_TRAINING_15_3SUM_H
#define CPP_TRAINING_15_3SUM_H

// problem:
// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n < 3)  return res;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int sum = -nums[i];
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (sum > nums[l] + nums[r]) {
                    ++l;
                } else if (sum < nums[l] + nums[r]) {
                    --r;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l+1])
                        ++l;
                    ++l;
                }
            }
        }
        return res;
    }
};

#endif //CPP_TRAINING_15_3SUM_H
