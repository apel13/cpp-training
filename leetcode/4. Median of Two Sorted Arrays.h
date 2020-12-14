//
// Created by apel on 11.12.2020.
//

#ifndef CPP_TRAINING_4_MEDIAN_OF_TWO_SORTED_ARRAYS_H
#define CPP_TRAINING_4_MEDIAN_OF_TWO_SORTED_ARRAYS_H

// problem:
// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // O(n + m) :(
        size_t n1 = nums1.size(), n2 = nums2.size();
        int iter = (n1 + n2) / 2 + 1;
        int cur = -1;
        int last = -1;
        size_t i = 0, j = 0;
        while (iter--) {
            last = cur;
            if (j >= n2 || i < n1 && nums1[i] < nums2[j]) {
                cur = nums1[i];
                ++i;
            } else {
                cur = nums2[j];
                ++j;
            };
        }

        if ((n1 + n2) % 2 != 0)
            return cur;
        return (last + cur) / 2.0;
    }
};

#endif //CPP_TRAINING_4_MEDIAN_OF_TWO_SORTED_ARRAYS_H
