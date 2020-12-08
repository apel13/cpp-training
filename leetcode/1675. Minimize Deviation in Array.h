//
// Created by apel on 06.12.2020.
//

#ifndef CPP_TRAINING_1675_MINIMIZE_DEVIATION_IN_ARRAY_H
#define CPP_TRAINING_1675_MINIMIZE_DEVIATION_IN_ARRAY_H

// problem:
// https://leetcode.com/problems/minimize-deviation-in-array/

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        size_t n = nums.size();
        for_each(nums.begin(), nums.end(), [](auto &i) {
            if (i & 1) i = i << 1;
        });
        set<int> s(nums.begin(), nums.end());

        int res = INT_MAX;

        while (true) {

            auto it_min = s.begin();
            auto it_max = std::prev(s.end());
            res = min(res, *it_max - *it_min);
            if (*it_max % 2) return res;
            else {
                s.insert(*it_max / 2);
                s.erase(it_max);
            }
        }
        return res;
    }
};

#endif //CPP_TRAINING_1675_MINIMIZE_DEVIATION_IN_ARRAY_H
