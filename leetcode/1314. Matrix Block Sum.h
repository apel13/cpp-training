//
// Created by apel on 28.12.2020.
//

#ifndef CPP_TRAINING_1314_MATRIX_BLOCK_SUM_H
#define CPP_TRAINING_1314_MATRIX_BLOCK_SUM_H

// problem:
// https://leetcode.com/problems/matrix-block-sum/

class Solution {
public:
    // fast
    vector <vector<int>> matrixBlockSum(vector <vector<int>> &r, int k) {
        int n = r.size();
        int m = r[0].size();

        for (int i = 1; i < n; ++i)
            r[i][0] += r[i - 1][0];
        for (int i = 1; i < m; ++i)
            r[0][i] += r[0][i - 1];

        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                r[i][j] += r[i - 1][j] + r[i][j - 1] - r[i - 1][j - 1];

        vector <vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int max_i = std::min(i + k, n - 1);
                int max_j = std::min(j + k, m - 1);
                bool fi = i - k - 1 >= 0;
                bool fj = j - k - 1 >= 0;
                res[i][j] = r[max_i][max_j]
                            - (fj ? r[max_i][j - k - 1] : 0)
                            - (fi ? r[i - k - 1][max_j] : 0)
                            + ((fj && fi) ? r[i - k - 1][j - k - 1] : 0);
            }
        }
        return res;
    }

    // slow
    vector <vector<int>> matrixBlockSum2(vector <vector<int>> &mat, int K) {
        int n = mat.size(), m = mat[0].size();
        vector <vector<int>> res(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {

                for (int ik = std::max(0, i - K); ik <= std::min(n - 1, i + K); ++ik) {
                    for (int jk = std::max(0, j - K); jk <= std::min(m - 1, j + K); ++jk) {
                        res[ik][jk] += mat[i][j];
                    }
                }
            }
        }
        return res;
    }
};

#endif //CPP_TRAINING_1314_MATRIX_BLOCK_SUM_H
