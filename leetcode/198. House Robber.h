#pragma once 

// problem:
// https://leetcode.com/problems/house-robber/ 

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        for (int i = 2; i < n; ++i) {
            if (i == 2) 
                nums[i] += nums[i-2];
            else 
                nums[i] += std::max(nums[i-2], nums[i-3]); 
        }
        return std::max(nums[n-1], nums[n-2]);
    }
};