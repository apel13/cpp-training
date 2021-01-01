//
// Created by apel on 31.12.2020.
//

#ifndef CPP_TRAINING_542_01_MATRIX_H
#define CPP_TRAINING_542_01_MATRIX_H

// problem:
// https://leetcode.com/problems/01-matrix/

class Solution {
public:
    // 99.94%, 100 %
    vector<vector<int>> updateMatrix(vector<vector<int>> &ma) {
        vector<vector<int>> matrix(std::move(ma));
        int n = matrix.size();
        int m = matrix[0].size();

        int max = std::max(n,m) + 1;
        if (matrix[0][0]) matrix[0][0] = max;

        for (int i = 1; i < n; ++i)
            if (matrix[i][0])
                matrix[i][0] = matrix[i - 1][0] + 1;

        for (int i = 1; i < m; ++i)
            if (matrix[0][i])
                matrix[0][i] = matrix[0][i - 1] + 1;

        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                if (matrix[i][j])
                    matrix[i][j] = std::min(matrix[i - 1][j], matrix[i][j - 1]) + 1;

        for (int i = n - 2; i >= 0; --i)
            if (matrix[i][m - 1])
                matrix[i][m - 1] = std::min(matrix[i][m - 1], matrix[i + 1][m - 1] + 1);

        for (int i = m - 2; i >= 0; --i)
            if (matrix[n - 1][i])
                matrix[n - 1][i] = std::min(matrix[n - 1][i], matrix[n - 1][i + 1] + 1);

        for (int i = n - 2; i >= 0; --i)
            for (int j = m - 2; j >= 0; --j)
                if (matrix[i][j])
                    matrix[i][j] = std::min(matrix[i][j], std::min(matrix[i + 1][j], matrix[i][j + 1]) + 1);
        return matrix;
    }
};

#endif //CPP_TRAINING_542_01_MATRIX_H
