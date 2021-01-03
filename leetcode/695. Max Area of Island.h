//
// Created by apel on 03.01.2021.
//

#ifndef CPP_TRAINING_695_MAX_AREA_OF_ISLAND_H
#define CPP_TRAINING_695_MAX_AREA_OF_ISLAND_H

// problem:
// https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    // 98.92 / 98.57
    int maxAreaOfIsland(vector<vector<int>> &_grid) {
        grid = std::move(_grid);
        n = grid.size();
        m = grid[0].size();

        int max = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j])
                    max = std::max(max, dfs(i, j));
            }
        }
        return max;
    }

    int dfs(int i, int j) {
        if (0 <= i && i < n
            && 0 <= j && j < m
            && grid[i][j]) {
            grid[i][j] = 0;
            return 1
                   + dfs(i - 1, j)
                   + dfs(i, j + 1)
                   + dfs(i + 1, j)
                   + dfs(i, j - 1);
        }
        return 0;
    }

    int n, m;
    vector<vector<int>> grid;
};

#endif //CPP_TRAINING_695_MAX_AREA_OF_ISLAND_H
