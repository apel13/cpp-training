//
// Created by apel on 29.12.2020.
//

#ifndef CPP_TRAINING_1696_JUMP_GAME_VI_H
#define CPP_TRAINING_1696_JUMP_GAME_VI_H

// problem:
// https://leetcode.com/problems/jump-game-vi/

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> d{0};
        for (int i = 1; i < nums.size(); ++i) {
            if (d.front() + k < i)
                d.pop_front();
            nums[i] += nums[d.front()];
            while (!d.empty() && nums[d.back()] <= nums[i]) d.pop_back();
            d.push_back(i);
        }
        return nums.back();
    }
};

#endif //CPP_TRAINING_1696_JUMP_GAME_VI_H
