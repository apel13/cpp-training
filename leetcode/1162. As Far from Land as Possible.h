//
// Created by apel on 03.01.2021.
//

#ifndef CPP_TRAINING_1162_AS_FAR_FROM_LAND_AS_POSSIBLE_H
#define CPP_TRAINING_1162_AS_FAR_FROM_LAND_AS_POSSIBLE_H

// problem:
// https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution {
public:
    // 99.18% / 96.00 %
    int maxDistance(vector<vector<int>> &grid) {
        int n = grid.size();
        bool noWater = true;
        bool noLand = true;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j]) {
                    noLand = false;
                    grid[i][j] = 0;
                } else {
                    noWater = false;
                    grid[i][j] = 1;
                }
        if (noWater || noLand) return -1;
        if (grid[0][0] == 1) grid[0][0] = 2 * n + 1;

        for (int i = 1; i < n; ++i) {
            if (grid[0][i] != 0)
                grid[0][i] = grid[0][i - 1] + 1;
            if (grid[i][0] != 0)
                grid[i][0] = grid[i - 1][0] + 1;
        }
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < n; ++j)
                if (grid[i][j] != 0)
                    grid[i][j] = std::min(grid[i - 1][j], grid[i][j - 1]) + 1;

        for (int i = n - 2; i >= 0; --i) {
            if (grid[n - 1][i] != 0)
                grid[n - 1][i] = std::min(grid[n - 1][i],
                                          grid[n - 1][i + 1] + 1);
            if (grid[i][n - 1] != 0)
                grid[i][n - 1] = std::min(grid[i][n - 1],
                                          grid[i + 1][n - 1] + 1);
        }
        for (int i = n - 2; i >= 0; --i)
            for (int j = n - 2; j >= 0; --j)
                if (grid[i][j] != 0)
                    grid[i][j] = std::min(grid[i][j],
                                          std::min(grid[i][j + 1], grid[i + 1][j]) + 1);
        int answer = -1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                answer = std::max(answer, grid[i][j]);
        return answer;
    }
};

#endif //CPP_TRAINING_1162_AS_FAR_FROM_LAND_AS_POSSIBLE_H
