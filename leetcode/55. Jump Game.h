//
// Created by apel on 12.12.2020.
//

#ifndef CPP_TRAINING_55_JUMP_GAME_H
#define CPP_TRAINING_55_JUMP_GAME_H

// problem:
// https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(); if (n == 1) return true;
        if (nums[0] == 0) return false;

        int i = 1, ni = 1;
        int gr = nums[0];
        while (i < n) {
            if (i + nums[i] >= ni + nums[ni])
                ni = i;
            if (i == gr) {
                if (i != n - 1 && nums[ni] == 0) return false;
                gr = ni + nums[ni];
                ni = i + 1;
            }
            ++i;
        }
        return true;
    }
};

#endif //CPP_TRAINING_55_JUMP_GAME_H
