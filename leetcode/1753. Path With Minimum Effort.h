#pragma once 

// problem:
// https://leetcode.com/problems/path-with-minimum-effort/ 

class Solution {
public:
    #define unlikely(expr)  __builtin_expect(!!(expr), 0)
    
    // 94.49% / 85.90%
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        using PQT = pair<int, pair<short, short>>;
        priority_queue<PQT, vector<PQT>, std::greater<PQT>> pq;
        // vector<vector<bool>> visited(n, vector<bool>(m, false));
        array<array<bool, 100>, 100> visited = { false };

        pq.emplace(0, make_pair(0, 0));
        while (!pq.empty()) {
            int ef = pq.top().first;
            int x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();

            if (visited[x][y]) continue;
            if (unlikely(x == n - 1 && y == m - 1)) return ef;

            visited[x][y] = true;

            for (int k = 0; k < 4; ++k) {
                int nx = x + dirs[k],
                    ny = y + dirs[k + 1];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny]) {
                    pq.emplace(
                        std::max(ef, std::abs(heights[x][y] - heights[nx][ny])),
                        make_pair(nx, ny)
                    );
                }

            }
        }
        return -1;
    }
private:
    static constexpr int dirs[5] = { -1, 0, 1, 0, -1 };
};