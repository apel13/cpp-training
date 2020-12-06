//
// Created by apel on 05.12.2020.
//

#ifndef CPP_TRAINING_1481_LEAST_NUMBER_OF_UNIQUE_INTEGERS_AFTER_K_REMOVALS_H
#define CPP_TRAINING_1481_LEAST_NUMBER_OF_UNIQUE_INTEGERS_AFTER_K_REMOVALS_H

// problem:
// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> m;
        for (int &i : arr)
            ++m[i];
        vector<pair<int, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](auto &p1, auto &p2) {
            return p1.second < p2.second;
        });
        int res = v.size();
        for (auto & i : v) {
            if (i.second <= k) {
                k -= i.second;
                --res;
            } else break;
        }
        return res;
    }
};

#endif //CPP_TRAINING_1481_LEAST_NUMBER_OF_UNIQUE_INTEGERS_AFTER_K_REMOVALS_H
