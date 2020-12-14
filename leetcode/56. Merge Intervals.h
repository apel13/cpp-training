//
// Created by apel on 13.12.2020.
//

#ifndef CPP_TRAINING_56_MERGE_INTERVALS_H
#define CPP_TRAINING_56_MERGE_INTERVALS_H

// problem:
// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](vector<int> &p1, vector<int> &p2) {
            return p1[0] < p2[0];
        });
        vector <vector<int>> res;
        res.push_back(intervals[0]);

        for (size_t i = 1; i < intervals.size(); ++i)
            if (intervals[i][0] <= res.back()[1])
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            else
                res.push_back(intervals[i]);
        return res;
    }
};

#endif //CPP_TRAINING_56_MERGE_INTERVALS_H
