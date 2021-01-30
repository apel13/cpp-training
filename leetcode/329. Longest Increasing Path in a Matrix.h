#pragma once 

// problem:
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/ 

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));

        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0, j < m; ++j)
                ans = std::max(ans, helper(i, j, matrix));

        return ans;
    }

    int helper(int i, int j, vector<vector<int>>& matrix) {
        if (dp[i][j] != -1) return dp[i][j];
        dp[i][j] = 0;

        for (int k = 0; k < 4; ++k) {
            int ni = i + dirs[k];
            int nj = j + dirs[k + 1];

            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

            if (matrix[i][j] < matrix[ni][nj])
                dp[i][j] = std::max(dp[i][j], helper(ni, nj, matrix));
        }
        return dp[i][j] + 1;
    }

private:
    int n, m;
    vector<vector<int>> dp;
    vector<int> dirs = { -1, 0, 1, 0, -1 };
};