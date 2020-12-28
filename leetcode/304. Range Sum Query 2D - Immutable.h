//
// Created by apel on 27.12.2020.
//

#ifndef CPP_TRAINING_304_RANGE_SUM_QUERY_2D_IMMUTABLE_H
#define CPP_TRAINING_304_RANGE_SUM_QUERY_2D_IMMUTABLE_H

// problem:
// https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int n = matrix.size();if (!n) return;
        int m= matrix[0].size();
        r = std::move(matrix);
        for (int i = 1; i < n; ++i)
            r[i][0] += r[i - 1][0];
        for (int i = 1; i < m; ++i)
            r[0][i] += r[0][i - 1];

        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                r[i][j] += r[i - 1][j] + r[i][j - 1] - r[i - 1][j - 1];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return r[row2][col2]
               - ((row1 > 0) ? r[row1 - 1][col2] : 0)
               - ((col1 > 0) ? r[row2][col1 - 1] : 0)
               + ((col1 > 0) && (row1 > 0) ? r[row1 - 1][col1 - 1] : 0);
    }
    vector<vector<int>> r;
};

#endif //CPP_TRAINING_304_RANGE_SUM_QUERY_2D_IMMUTABLE_H
