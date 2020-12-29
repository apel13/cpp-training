//
// Created by apel on 29.12.2020.
//

#ifndef CPP_TRAINING_76_MINIMUM_WINDOW_SUBSTRING_H
#define CPP_TRAINING_76_MINIMUM_WINDOW_SUBSTRING_H

// problem:
// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> mt;
        std::unordered_map<char, int> ms;

        for (auto &c : t)
            mt[c]++;
        int t_alp_size = mt.size();
        int cur_alp_size = 0;

        int min = -1, min_l = 0, l = 0, r = 0;

        while (r < s.size()) {
            if (mt[s[r]] == 0) {++r;continue;}
            if (++ms[s[r]] == mt[s[r]]) cur_alp_size++;

            while (l <= r && cur_alp_size == t_alp_size) {
                if (mt[s[l]] == 0) {++l;continue;}
                else if (ms[s[l]] == mt[s[l]]) {
                    if (min == -1 || r - l < min) {
                        min = r - l;
                        min_l = l;
                    }
                    cur_alp_size--;
                }
                ms[s[l]]--;
                ++l;
            }
            ++r;
        }
        return s.substr(min_l, min + 1);
    }
};

#endif //CPP_TRAINING_76_MINIMUM_WINDOW_SUBSTRING_H
