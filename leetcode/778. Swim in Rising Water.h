//
// Created by apel on 06.01.2021.
//

#ifndef CPP_TRAINING_778_SWIM_IN_RISING_WATER_H
#define CPP_TRAINING_778_SWIM_IN_RISING_WATER_H

// problem:
// https://leetcode.com/problems/swim-in-rising-water/

class Solution {
public:
    struct point {
        point(int _i, int _j, int _w) :i(_i), j(_j), w(_w){}
        int i, j;
        int w;

        bool operator<(const point &p) const{
            return this->w > p.w;
        }
    };

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        std::priority_queue<point> q;
        std::vector<int> dirs = {-1, 0, 1, 0, -1};

        q.push(point(0,0, grid[0][0]));
        visited[0][0] = true;

        while (!q.empty()) {
            auto top = q.top(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int curI = top.i + dirs[i];
                int curJ = top.j + dirs[i + 1];
                if (curI == n-1 && curJ == n-1) return std::max(top.w, grid[curI][curJ]);
                if (0 <= curI && curI < n &&
                    0 <= curJ && curJ < n &&
                    !visited[curI][curJ]) {
                    visited[curI][curJ] = true;
                    q.push(point(curI, curJ, std::max(grid[curI][curJ], top.w)));
                }
            }
        }
        return -1;
    }
};

#endif //CPP_TRAINING_778_SWIM_IN_RISING_WATER_H
