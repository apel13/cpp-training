//
// Created by apel on 03.01.2021.
//

#ifndef CPP_TRAINING_1124_LONGEST_WELL_PERFORMING_INTERVAL_H
#define CPP_TRAINING_1124_LONGEST_WELL_PERFORMING_INTERVAL_H

// problem:
// https://leetcode.com/problems/longest-well-performing-interval/

class Solution {
public:
    int longestWPI(vector<int> &hours) {

        unordered_map<int, int> m;

        int res = 0;
        for (int i = 0, sum = 0; i < hours.size(); ++i) {
            sum += hours[i] > 0 ? 1 : -1;

            if (sum > 0) res = i + 1;
            else {
                if (m.count(sum - 1)) {
                    res = std::max(res, i - m[sum - 1] + 1);
                } else {
                    m[sum] = i;
                }
            }
        }
        return res;
    }
};

#endif //CPP_TRAINING_1124_LONGEST_WELL_PERFORMING_INTERVAL_H
