//
// Created by apel on 06.01.2021.
//

#ifndef CPP_TRAINING_827_MAKING_A_LARGE_ISLAND_H
#define CPP_TRAINING_827_MAKING_A_LARGE_ISLAND_H

// problem:
// https://leetcode.com/problems/making-a-large-island/

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    areas.push_back(0);
                    dfs(i, j, grid);
                    ++cur_island;
                }
            }
        }
        int max = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0)
                    max = std::max(max, count(i, j, grid, areas) + 1);

        if (max == 0) max = *areas.begin();
        return max;
    }

    int count(const int &i, const int &j, vector<vector<int>>& grid, const vector<int> &areas) {
        unordered_set<int> st;
        for (int k = 0; k < 4; ++k) {
            int curI = i + dirs[k];
            int curJ = j + dirs[k + 1];
            if (0 <= curI && curI < n &&
                0 <= curJ && curJ < n &&
                grid[curI][curJ] != 0) {
                st.insert(grid[curI][curJ]);
            }
        }
        return std::accumulate(st.begin(), st.end(), 0, [&areas](int a, const int &b) {return a + areas[b - 100];});
    }

    void dfs(int i, int j, vector<vector<int>>& grid) {
        if (0 <= i && i < n &&
            0 <= j && j < n &&
            grid[i][j] == 1)
        {
            grid[i][j] = cur_island;
            areas.back()++;
            for (int k = 0; k < 4; ++k)
                dfs(i + dirs[k], j + dirs[k+1], grid);
        }
    }
    int n;
    int cur_island = 100;
    std::vector<int> dirs = {-1, 0, 1, 0, -1};
    vector<int> areas;
};

#endif //CPP_TRAINING_827_MAKING_A_LARGE_ISLAND_H
