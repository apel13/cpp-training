#pragma once 

// problem:
// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/ 

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<vector<int>> s(
            std::make_move_iterator(begin(points)),
            std::make_move_iterator(end(points)));

        int ret = 0;
        for (auto it = begin(s); it != prev(end(s)); ++it) {
            ret = std::max(ret, (*next(it))[0] - (*it)[0]);
        }
        return ret;
    }


    int maxWidthOfVerticalArea2(vector<vector<int>>& points) {
        std::sort(begin(points), end(points), 
        [](const vector<int> &lhs, const vector<int> &rhs){
            return lhs[0] < rhs[0];
        });

        int ret = 0;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] != points[i-1][0]) {
                ret = std::max(ret, points[i][0] - points[i-1][0]);
            }
        }
        return ret;
    }
};