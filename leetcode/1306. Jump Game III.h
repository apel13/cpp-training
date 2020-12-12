//
// Created by apel on 12.12.2020.
//

#ifndef CPP_TRAINING_1306_JUMP_GAME_III_H
#define CPP_TRAINING_1306_JUMP_GAME_III_H

// problem:
// https://leetcode.com/problems/jump-game-iii/

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int t = q.front(); q.pop();
            if (arr[t] == 0) return true;
            if (arr[t] == -1) continue;

            if (t - arr[t] >= 0)
                q.push(t - arr[t]);
            if (t + arr[t] < n)
                q.push(t + arr[t]);
            arr[t] = -1;
        }
        return false;
    }
};

#endif //CPP_TRAINING_1306_JUMP_GAME_III_H
