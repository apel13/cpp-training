#pragma once

// problem:
// https://leetcode.com/problems/triangle/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size());
        for (int i = 0; i < triangle.size(); ++i)
            dp[i].resize(i + 1, 0);
        dp[0][0] = triangle[0][0];

        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 0; j < i + 1; ++j) {
                if (j == 0) dp[i][j] = dp[i - 1][j];
                else if (j == i) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][j - 1]);
                dp[i][j] +=  + triangle[i][j];
            }
        }
        return *std::min_element(dp.back().begin(), dp.back().end());
    }
};