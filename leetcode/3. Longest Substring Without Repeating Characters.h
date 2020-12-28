//
// Created by apel on 11.12.2020.
//

#ifndef CPP_TRAINING_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
#define CPP_TRAINING_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H

// problem:
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t n = s.size();
        if (n == 0) return 0;

        unordered_map<char, int> m;
        int max_length = 0;

        int p1 = 0, p2 = 0;
        while (p2 < n) {
            char c = s[p2];
            if (m[c] != 0) {
                max_length = max(max_length, p2 - p1);
                while (m[c] != 0) {
                    m[s[p1]]--;
                    p1++;
                }
            }
            m[c]++; p2++;
        }
        max_length = max(max_length, p2 - p1);
        return max_length;
    }
};

#endif //CPP_TRAINING_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
