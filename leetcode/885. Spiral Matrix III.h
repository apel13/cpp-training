//
// Created by apel on 11.01.2021.
//

#ifndef CPP_TRAINING_885_SPIRAL_MATRIX_III_H
#define CPP_TRAINING_885_SPIRAL_MATRIX_III_H

// problem:
// https://leetcode.com/problems/spiral-matrix-iii/

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int r, int c, int r0, int c0) {
        vector<vector<int>> spiralMatrix(r*c);
        std::vector<int> dirs = {0, 1, 0, -1, 0};
        int di = 0;
        int k = 0, step = 0;
        while (k < r * c) {
            if (di % 2 == 0) step++;
            for (int i = 0; i < step; ++i) {
                if (0 <= r0 && r0 < r && 0 <= c0 && c0 < c)
                    spiralMatrix[k++] = vector<int>{r0, c0};
                r0 += dirs[di];
                c0 += dirs[di+1];
            }
            di = (di + 1) % 4;
        }
        return spiralMatrix;
    }
};

#endif //CPP_TRAINING_885_SPIRAL_MATRIX_III_H
