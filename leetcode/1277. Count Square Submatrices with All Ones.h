//
// Created by apel on 26.12.2020.
//

#ifndef CPP_TRAINING_1277_COUNT_SQUARE_SUBMATRICES_WITH_ALL_ONES_H
#define CPP_TRAINING_1277_COUNT_SQUARE_SUBMATRICES_WITH_ALL_ONES_H

// problem:
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    int countSquares(vector<vector<int>> &m) {

        for (int i = 1; i < m.size(); ++i) {
            for (int j = 1; j < m[0].size(); ++j) {
                if (m[i][j]) {
                    m[i][j] = 1 + std::min(m[i - 1][j - 1],
                                           std::min(m[i - 1][j], m[i][j - 1]));
                }
            }
        }
        int res = 0;
        for (auto &vec : m)
            for (auto &el : vec)
                res += el;
        return res;
    }
};

#endif //CPP_TRAINING_1277_COUNT_SQUARE_SUBMATRICES_WITH_ALL_ONES_H
