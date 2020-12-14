//
// Created by apel on 13.12.2020.
//

#ifndef CPP_TRAINING_174_DUNGEON_GAME_H
#define CPP_TRAINING_174_DUNGEON_GAME_H

// problem:
// https://leetcode.com/problems/dungeon-game/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        size_t n = dungeon.size();
        size_t m = dungeon[0].size();

        dungeon[n-1][m-1] = std::max(0, -dungeon[n-1][m-1]);
        for (size_t i = n - 1; i > 0; --i)
            dungeon[i- 1][m-1] = max(0, dungeon[i][m-1] - dungeon[i-1][m-1]);
        for (size_t i = m - 1; i > 0 ; --i)
            dungeon[n-1][i-1] = max(0, dungeon[n-1][i] - dungeon[n-1][i-1]);
        for (size_t i = n - 1; i > 0; --i) {
            for (size_t j = m - 1; j > 0; --j) {
                dungeon[i - 1][j - 1] = std::max(std::min(dungeon[i - 1][j], dungeon[i][j - 1]) - dungeon[i-1][j-1], 0);
            }
        }
        return dungeon[0][0] + 1;
    }
};

#endif //CPP_TRAINING_174_DUNGEON_GAME_H
