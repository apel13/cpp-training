#pragma once 

// problem:
// https://leetcode.com/problems/reverse-words-in-a-string/ 

class Solution {
public:
    string reverseWords(string& s) {
        istringstream is(s); s.resize(0);
        string word;
        while (is >> word) {
            reverse(begin(word), end(word));
            s.append(word + " ");
        }
        if (!s.empty()) {
            s.pop_back();
            reverse(s.begin(), s.end());
        }
        return s;
    }
};