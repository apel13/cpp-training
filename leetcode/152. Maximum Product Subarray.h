//
// Created by apel on 08.01.2021.
//

#ifndef CPP_TRAINING_152_MAXIMUM_PRODUCT_SUBARRAY_H
#define CPP_TRAINING_152_MAXIMUM_PRODUCT_SUBARRAY_H

// problem:
// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max = nums[0];
        for (int i = 0, cur_l = 1, cur_r = 1; i < n; ++i) {
            cur_l = (cur_l ? cur_l : 1) * nums[i];
            cur_r = (cur_r ? cur_r : 1) * nums[n-1-i];
            max = std::max(max, std::max(cur_l, cur_r));
        }
        return max;
    }
};

#endif //CPP_TRAINING_152_MAXIMUM_PRODUCT_SUBARRAY_H
