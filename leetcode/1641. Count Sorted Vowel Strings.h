//
// Created by apel on 26.12.2020.
//

#ifndef CPP_TRAINING_1641_COUNT_SORTED_VOWEL_STRINGS_H
#define CPP_TRAINING_1641_COUNT_SORTED_VOWEL_STRINGS_H

// problem:
// https://leetcode.com/problems/count-sorted-vowel-strings/

class Solution {
public:
    int countVowelStrings(int n) {
        std::vector<vector<int>> m(n, vector<int>(5, 0));
        for (int i = 0; i < 5; ++i)
            m[0][i] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 5;++j) {
                for (int k = 0; k <= j; ++k) {
                    m[i][j] += m[i-1][k];
                }
            }
        }
        return std::accumulate(m[n-1].begin(), m[n-1].end(), 0);
    }
};

#endif //CPP_TRAINING_1641_COUNT_SORTED_VOWEL_STRINGS_H
