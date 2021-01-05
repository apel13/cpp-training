//
// Created by apel on 06.01.2021.
//

#ifndef CPP_TRAINING_934_SHORTEST_BRIDGE_H
#define CPP_TRAINING_934_SHORTEST_BRIDGE_H

// problem:
// https://leetcode.com/problems/max-area-of-island/

class Solution {
public:

    // mem o(n) :(
    int shortestBridge(vector<vector<int>>& a) {
        n = a.size();
        vector<vector<int>> b(n, vector<int>(n,0));

        bool isOk = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                if (a[i][j] == 1) {
                    dfs(i, j, a, b);
                    isOk = true;
                    break;
                }
            if (isOk)
                break;
        }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                a[i][j] = a[i][j] ? 1 : 0;
        int MAX = n * n + 1;
        if (a[0][0] == 1) a[0][0] = MAX;
        for (int i = 1; i < n; ++i) {
            if (a[0][i])
                a[0][i] = a[0][i-1] + 1;
            if (a[i][0])
                a[i][0] = a[i-1][0] + 1;
        }
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < n; ++j)
                if (a[i][j])
                    a[i][j] = std::min(a[i-1][j], a[i][j-1]) + 1;
        for (int i = n - 2; i >= 0; --i) {
            if (a[i][n-1])
                a[i][n-1] = std::min(a[i][n-1], a[i+1][n-1] + 1);
            if (a[n-1][i])
                a[n-1][i] = std::min(a[n-1][i], a[n-1][i+1] + 1);
        }
        for (int i = n - 2; i >= 0; --i)
            for (int j = n - 2; j >= 0; --j)
                if (a[i][j])
                    a[i][j] = std::min(a[i][j], std::min(a[i+1][j], a[i][j+1]) + 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << a[i][j] << " ";
            cout << endl;
        }
        int ans = MAX;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                if (b[i][j] == 1)
                    ans = std::min(ans, a[i][j]);
            }
        return ans;
    }
    void dfs(int i, int j, vector<vector<int>>& a, vector<vector<int>>& b) {
        if (0 <= i && i < n &&
            0 <= j && j < n &&
            a[i][j] == 1)
        {
            a[i][j] = 0;
            b[i][j] = 1;
            for (int k = 0; k < 4; ++k)
                dfs(i + dirs[k], j + dirs[k + 1], a, b);
        }
    }
    int n;
    vector<int> dirs = {-1, 0, 1, 0, -1};
};

#endif //CPP_TRAINING_934_SHORTEST_BRIDGE_H
