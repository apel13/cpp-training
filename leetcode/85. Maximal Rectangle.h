//
// Created by apel on 06.12.2020.
//

#ifndef CPP_TRAINING_85_MAXIMAL_RECTANGLE_H
#define CPP_TRAINING_85_MAXIMAL_RECTANGLE_H

// problem:
// https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        size_t n = matrix.size();
        if (n == 0) return 0;
        size_t m = matrix[0].size();
        if (m == 0) return 0;

        vector<int> cur_h(m, 0);
        for (size_t i = 0; i < m; ++i) {
            cur_h[i] = matrix[0][i] - '0';
        }
        int max_area = 0;
        max_area = max(max_area, largestRectangleArea(cur_h));

        for (size_t i = 1; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    cur_h[j] += 1;
                } else {
                    cur_h[j] = 0;
                }
            }
            max_area = max(max_area, largestRectangleArea(cur_h));
        }
        return max_area;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        int max_area = 0;
        stack<int> s;

        int i = 0;
        int t;
        while (i < n) {
            if (s.empty() || heights[s.top()] <= heights[i]) {
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

#endif //CPP_TRAINING_85_MAXIMAL_RECTANGLE_H
