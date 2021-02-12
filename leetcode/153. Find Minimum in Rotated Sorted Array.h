#pragma once 

// problem:
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/ 

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, m;
        while (l < r) {
            m = (l + r) / 2;
            if (nums[m] > nums[r]) l = m + 1;
            else r = m;
        }
        return nums[l];
    }
};