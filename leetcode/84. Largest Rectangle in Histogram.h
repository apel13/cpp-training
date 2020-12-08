//
// Created by apel on 08.12.2020.
//

#ifndef CPP_TRAINING_84_LARGEST_RECTANGLE_IN_HISTOGRAM_H
#define CPP_TRAINING_84_LARGEST_RECTANGLE_IN_HISTOGRAM_H

// problem:
// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        int max_area = 0;
        stack<int> s;

        int i = 0;
        int t;
        while (i < n) {
            if (s.empty() || heights[s.top()] <= heights[i]){
                s.push(i++);
            } else {
                t = s.top();
                s.pop();
                if (s.empty())
                    max_area = max(max_area, heights[t] * i);
                else
                    max_area = max(max_area, heights[t] * (i - 1 - s.top()));
            }
        }
        while (!s.empty()) {
            t = s.top();
            s.pop();
            if (s.empty())
                max_area = max(max_area, heights[t] * i);
            else
                max_area = max(max_area, heights[t] * (i - s.top() - 1));

        }
        return max_area;
    }
};

#endif //CPP_TRAINING_84_LARGEST_RECTANGLE_IN_HISTOGRAM_H
