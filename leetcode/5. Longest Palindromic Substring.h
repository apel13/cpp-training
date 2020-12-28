//
// Created by apel on 28.12.2020.
//

#ifndef CPP_TRAINING_5_LONGEST_PALINDROMIC_SUBSTRING_H
#define CPP_TRAINING_5_LONGEST_PALINDROMIC_SUBSTRING_H

// problem:
// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        auto max_l = [&s] (int &l, int &r, int iter) {
            int res = 0;
            while (iter-- && s[l--] == s[r++]) ++res;
            return res;
        };
        int n = s.size();
        int max = 1;
        int max_i = 0;
        int l, r, len;
        for (int i = 0; i < n; ++i) {
            l = i - 1, r = i + 1;
            len = max_l(l,r,std::min(i, n - r)) * 2 + 1;
            if (len > max) {max=len;max_i=i;}
            if (s[i] != s[i+1]) continue;
            l = i - 1, r = i + 2;
            len = max_l(l,r,std::min(i, n - r)) * 2 + 2;
            if (len > max) {max=len;max_i=i;}
        }
        return s.substr(max_i - (max - 1)/2, max);
    }
};

#endif //CPP_TRAINING_5_LONGEST_PALINDROMIC_SUBSTRING_H
