//
// Created by apel on 06.12.2020.
//

#ifndef CPP_TRAINING_78_SUBSETS_H
#define CPP_TRAINING_78_SUBSETS_H

// problem:
// https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        size_t n = nums.size();
        vector<vector<int>> res;
        res.reserve(1 << n);
        vector<int> tmp;

        for (size_t i = 0; i < (1 << n); ++i) {
            tmp.clear();
            for (size_t j = 0; j < n; ++j) {
                if (i & (1 << j))
                    tmp.push_back(nums[j]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

#endif //CPP_TRAINING_78_SUBSETS_H
