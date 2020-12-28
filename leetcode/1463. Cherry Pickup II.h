//
// Created by apel on 27.12.2020.
//

#ifndef CPP_TRAINING_1463_CHERRY_PICKUP_II_H
#define CPP_TRAINING_1463_CHERRY_PICKUP_II_H

// problem:
// https://leetcode.com/problems/cherry-pickup-ii/

class Solution {
public:
    int cherryPickup(vector<vector<int>> &g) {
        int n = g.size();
        int m = g[0].size();

        vector<vector<vector<int>>> dp(n,
                                       vector<vector<int>>(m,
                                               vector<int>(m, 0)));

        for (int j1 = 0; j1 < m; ++j1)
            for (int j2 = j1 + 1; j2 < m; ++j2)
                dp[n - 1][j1][j2] = g[n - 1][j1] + g[n - 1][j2];

        for (int i = n - 2; i >= 0; --i) {
            for (int j1 = 0; j1 < m; ++j1) {
                for (int j2 = j1 + 1; j2 < m; ++j2) {
                    int max = INT_MIN;
                    for (int k1 = std::max(0, j1 - 1); k1 <= min(m - 1, j1 + 1); ++k1) {
                        for (int k2 = std::max(k1 + 1, j2 - 1); k2 <= min(m - 1, j2 + 1); ++k2) {
                            max = std::max(max, dp[i + 1][k1][k2]);
                        }
                    }
                    dp[i][j1][j2] = g[i][j1] + g[i][j2] + max;
                }
            }
        }
        return dp[0][0][m-1];
    }
};

#endif //CPP_TRAINING_1463_CHERRY_PICKUP_II_H
