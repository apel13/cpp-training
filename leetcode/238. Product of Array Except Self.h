//
// Created by apel on 10.12.2020.
//

#ifndef CPP_TRAINING_238_PRODUCT_OF_ARRAY_EXCEPT_SELF_H
#define CPP_TRAINING_238_PRODUCT_OF_ARRAY_EXCEPT_SELF_H

// problem:
// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for (size_t i = 1; i < n; ++i) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        for (size_t i = n - 1; i > 0; --i) {
            right[i - 1] = right[i] * nums[i];
        }
        for (size_t i = 0; i < n; ++i) {
            right[i]*=left[i];
        }
        return right;
    }
};

#endif //CPP_TRAINING_238_PRODUCT_OF_ARRAY_EXCEPT_SELF_H
