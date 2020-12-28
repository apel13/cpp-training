//
// Created by apel on 29.12.2020.
//

#ifndef CPP_TRAINING_1402_REDUCING_DISHES_H
#define CPP_TRAINING_1402_REDUCING_DISHES_H

// problem:
// https://leetcode.com/problems/reducing-dishes/

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();

        std::sort(satisfaction.begin(), satisfaction.end());
        auto lzp = std::find_if(satisfaction.begin(), satisfaction.end(), [](int &i) {
            return i > -1;
        });
        int el_idx = std::distance(satisfaction.begin(), lzp);

        int res = 0;
        int num = 0;
        int sum = 0;

        for (int i = el_idx; i < n; ++i) {
            res += ++num * satisfaction[i];
            sum += satisfaction[i];
        }
        while (--el_idx > -1) {
            if (satisfaction[el_idx] + sum > 0) {
                res += sum + satisfaction[el_idx];
                sum += satisfaction[el_idx];

            } else break;
        }
        return res;

    }
};

#endif //CPP_TRAINING_1402_REDUCING_DISHES_H
