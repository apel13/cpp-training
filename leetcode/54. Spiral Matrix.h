//
// Created by apel on 11.01.2021.
//

#ifndef CPP_TRAINING_54_SPIRAL_MATRIX_H
#define CPP_TRAINING_54_SPIRAL_MATRIX_H

// problem:
// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<int> answer; answer.reserve(n * m);
        std::vector<int> dirs = {0, 1, 0, -1, 0};
        int di = 0;
        int i = 0, j = -1;
        while (answer.size() < n * m) {
            while (checkCell(i + dirs[di], j + dirs[di + 1]) &&
                   matrix[i + dirs[di]][j + dirs[di + 1]] != 101) {
                i += dirs[di];
                j += dirs[di + 1];
                answer.push_back(matrix[i][j]);
                matrix[i][j] = 101;
            }
            di = (di + 1) % 4;
        }
        return answer;
    }

    inline bool checkCell(const int &i, const int &j) const {
        return 0 <= i && i < n && 0 <= j && j < m;
    }
    int n, m;
};

#endif //CPP_TRAINING_54_SPIRAL_MATRIX_H
