//
// Created by apel on 03.01.2021.
//

#ifndef CPP_TRAINING_200_NUMBER_OF_ISLANDS_H
#define CPP_TRAINING_200_NUMBER_OF_ISLANDS_H

// problem:
// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int numIslands(vector <vector<char>> &grid) {
        n = grid.size();
        m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] - '0') {
                    ++res;
                    bfs(i, j, grid);
                }
        return res;
    }
    void bfs(int i, int j, vector <vector<char>> &grid) {
        if (0 <= i && i < n &&
            0 <= j && j < m &&
            grid[i][j] - '0') {
            grid[i][j] = '0';
            bfs(i - 1, j, grid);
            bfs(i, j + 1, grid);
            bfs(i + 1, j, grid);
            bfs(i, j - 1, grid);
        }
    }
    int n, m;
};

#endif //CPP_TRAINING_200_NUMBER_OF_ISLANDS_H
