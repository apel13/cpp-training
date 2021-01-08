//
// Created by apel on 08.01.2021.
//

#ifndef CPP_TRAINING_699_FALLING_SQUARES_H
#define CPP_TRAINING_699_FALLING_SQUARES_H

// problem:
// https://leetcode.com/problems/falling-squares/

class Solution {
public:
    // 68.67% / 40.67% i dont know segment tree :(
    vector<int> fallingSquares(vector<vector<int>> &positions) {
        set<int> coords;
        for (auto &rect : positions) {
            coords.insert(rect[0]);
            coords.insert(rect[0] + rect[1]);
        }
        unordered_map<int, int> to_zip;
        int i = 0;
        for (auto &el : coords)
            to_zip[el] = i++;

        vector<int> heights(coords.size() + 1, 0);
        vector<int> res; res.reserve(positions.size() + 1);

        int cur_max = 0;
        for (auto & rect : positions) {
            int left = to_zip[rect[0]];
            int right = to_zip[rect[0] + rect[1]];

            int side_max = rect[1] + *std::max_element(   heights.begin() + left,
                                                          heights.begin() + right);
            std::fill(heights.begin() + left,
                      heights.begin() + right, side_max);

            cur_max = std::max(cur_max, side_max);
            res.push_back(cur_max);
        }
        return res;
    }
};

#endif //CPP_TRAINING_699_FALLING_SQUARES_H
