//
// Created by apel on 10.12.2020.
//

#ifndef CPP_TRAINING_42_TRAPPING_RAIN_WATER_H
#define CPP_TRAINING_42_TRAPPING_RAIN_WATER_H

// problem:
// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    // stack
    int trap(vector<int>& height) {
        int n = height.size(); if (n == 0) return 0;
        stack<int> s;

        int res = 0;
        for (size_t i = 0; i < n; ++i) {
            if (s.empty() || height[i] <= height[s.top()]) {
                s.push(i);
            } else {
                while (!s.empty() && height[s.top()] < height[i]) {
                    int t = height[s.top()]; s.pop();
                    if (s.empty()) {
                        break;
                    }
                    res += (min(height[i], height[s.top()]) - t) * (i - 1 - s.top());
                }
                s.push(i);
            }
        }
        return res;
    }


    // 2 pointer
    int trap2(vector<int>& height) {
        if (height.size() == 0) return 0;
        int left = 0, right = height.size() - 1;
        int max_left = 0, max_right = 0;
        int res = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= max_left) max_left = height[left];
                else res+=max_left - height[left];
                ++left;
            } else {
                if (height[right] >= max_right) max_right = height[right];
                else res+=max_right - height[right];
                --right;
            }
        }
        return res;
    }
};

#endif //CPP_TRAINING_42_TRAPPING_RAIN_WATER_H
