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
        size_t n1 = nums1.size(), n2 = nums2.size();
        int iter = (n1 + n2 + 1) / 2;

        size_t p1 = 0, p2 = 0;
        while(iter--) {
            if (n1 == p1 || nums2[p2] < nums1[p1]) {
                ++p2;
            } else {
                ++p1;
            }
        }
        if ((n1 + n2) % 2 != 0) {
            if (p1 == n1)
        }
        double res;

        return 0;
    }
};

#endif //CPP_TRAINING_4_MEDIAN_OF_TWO_SORTED_ARRAYS_H
