//
// Created by apel on 11.12.2020.
//

#ifndef CPP_TRAINING_45_JUMP_GAME_II_H
#define CPP_TRAINING_45_JUMP_GAME_II_H

// problem:
// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(); if (n == 1) return 0;
        int i = 1, st = 1, ni = 1;
        int gr = nums[0];
        while (i < n) {
            if (i + nums[i] >= ni + nums[ni])
                ni = i;
            if (i == gr) {
                if (i != n - 1)
                    ++st;
                gr = ni + nums[ni];
                ni = i + 1;
            }
            ++i;
        }
        return st;
    }

    int jump_bad(vector<int>& nums) {
        size_t n = nums.size();
        if (n == 1) return 0;

        size_t i = 0;
        int steps = 0;
        while (i < n - 1) {
            if (i + nums[i] >= n - 1){
                steps++; break;
            }
            size_t max = 0;
            size_t max_j;
            for (size_t j = i + 1; j <= i + nums[i]; ++j) {
                if (j + nums[j] >= max) {
                    max = j + nums[j];
                    max_j = j;
                }
            }
            steps++;
            i = max_j;
        }
        return steps;
    }
};

#endif //CPP_TRAINING_45_JUMP_GAME_II_H
