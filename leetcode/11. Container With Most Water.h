//
// Created by apel on 10.12.2020.
//

#ifndef CPP_TRAINING_11_CONTAINER_WITH_MOST_WATER_H
#define CPP_TRAINING_11_CONTAINER_WITH_MOST_WATER_H

// problem:
// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int p1 = 0;
        int p2 = height.size() - 1;

        int res = 0;
        while (p1 < p2) {
            res = max(res,  (p2-p1) * min(height[p1], height[p2]));
            if (height[p1] > height[p2])
                p2--;
            else
                p1++;
        }
        return res;

    }
};

#endif //CPP_TRAINING_11_CONTAINER_WITH_MOST_WATER_H
