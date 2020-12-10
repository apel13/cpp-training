//
// Created by apel on 10.12.2020.
//

#ifndef CPP_TRAINING_221_MAXIMAL_SQUARE_H
#define CPP_TRAINING_221_MAXIMAL_SQUARE_H

// problem:
// https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        size_t n = matrix.size();
        size_t m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        int max = 0;
        for (size_t i = 0; i < n; ++i) {
            dp[i][0] = matrix[i][0] - '0';
            max = std::max(max, dp[i][0]);

        }
        for (size_t i = 0; i < m; ++i) {
            dp[0][i] = matrix[0][i] - '0';
            max = std::max(max, dp[0][i]);
        }

        for (size_t i = 1; i < n; ++i) {
            for (size_t j = 1; j < m; ++j) {
                if (matrix[i][j] - '0') {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    max = std::max(dp[i][j], max);
                } else dp[i][j] = 0;
            }
        }
        return max * max;
    }
};

#endif //CPP_TRAINING_221_MAXIMAL_SQUARE_H
