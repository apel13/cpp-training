//
// Created by apel on 11.01.2021.
//

#ifndef CPP_TRAINING_59_SPIRAL_MATRIX_II_H
#define CPP_TRAINING_59_SPIRAL_MATRIX_II_H

// problem:
// https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> answer(n, vector<int>(n, 0));
        std::vector<int> dirs = {0, 1, 0, -1, 0};
        int di = 0;
        int i = 0, j = -1;
        int k = 1;
        while (k < n * n + 1) {
            while (answer[(i + dirs[di] + n) % n][(j + dirs[di+1] + n) % n] == 0) {
                i += dirs[di];
                j += dirs[di + 1];
                answer[i][j] = k++;
            }
            di = (di + 1) % 4;
        }
        return answer;
    }
};

#endif //CPP_TRAINING_59_SPIRAL_MATRIX_II_H
