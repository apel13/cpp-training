//
// Created by apel on 14.12.2020.
//

#ifndef CPP_TRAINING_1288_REMOVE_COVERED_INTERVALS_H
#define CPP_TRAINING_1288_REMOVE_COVERED_INTERVALS_H

// problem:
// https://leetcode.com/problems/remove-covered-intervals/

class Solution {
public:
    int removeCoveredIntervals(vector <vector<int>> &intervals)
    {
        std::sort(intervals.begin(), intervals.end(), [](vector<int> &p1, vector<int> &p2) {
            return p1[0] == p2[0] ? p1[1] > p2[1] : p1[0] < p2[0];
        });
        size_t n = intervals.size();
        size_t res = n;
        size_t cur_i = 0;

        for (size_t i = 1; i < n; ++i)
            if (intervals[i][1] <= intervals[cur_i][1])
                --res;
            else
                cur_i = i;


        return res;
    }
};

#endif //CPP_TRAINING_1288_REMOVE_COVERED_INTERVALS_H
