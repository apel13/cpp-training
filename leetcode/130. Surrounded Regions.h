//
// Created by apel on 03.01.2021.
//

#ifndef CPP_TRAINING_130_SURROUNDED_REGIONS_H
#define CPP_TRAINING_130_SURROUNDED_REGIONS_H

// problem:
// https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    // 96.48% / 93.91%
    void solve(vector <vector<char>> &board) {
        n = board.size();
        if (n == 0) return;
        m = board[0].size();
        if (m == 0) return;

        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O')
                xfs(i, 0, board);
            if (board[i][m - 1] == 'O')
                xfs(i, m - 1, board);
        }

        for (int i = 1; i < m - 1; ++i) {
            if (board[0][i] == 'O')
                xfs(0, i, board);
            if (board[n - 1][i] == 'O')
                xfs(n - 1, i, board);
        }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'Q')
                    board[i][j] = 'O';
    }

    void xfs(int i, int j, vector <vector<char>> &board) {
        board[i][j] = 'Q';
        xfs_helper(i - 1, j, board);
        xfs_helper(i, j + 1, board);
        xfs_helper(i + 1, j, board);
        xfs_helper(i, j - 1, board);

    }

    void xfs_helper(int i, int j, vector <vector<char>> &board) {
        if (0 <= i && i < n &&
            0 <= j && j < m &&
            board[i][j] == 'O') {
            board[i][j] = 'Q';
            xfs_helper(i - 1, j, board);
            xfs_helper(i, j + 1, board);
            xfs_helper(i + 1, j, board);
            xfs_helper(i, j - 1, board);
        }
    }

    int n, m;
};

#endif //CPP_TRAINING_130_SURROUNDED_REGIONS_H
