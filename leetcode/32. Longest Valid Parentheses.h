//
// Created by apel on 28.12.2020.
//

#ifndef CPP_TRAINING_32_LONGEST_VALID_PARENTHESES_H
#define CPP_TRAINING_32_LONGEST_VALID_PARENTHESES_H

// problem:
// https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    // TODO stack2 and left/right traversing
    int longestValidParentheses(string s) {

    }

    // dp o(n), o(n)
    int longestValidParentheses2(const string& s) {
        std::vector<int> dp(s.size());
        int max = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = ((i - 2 >= 0) ? dp[i-2] : 0) + 2;
                } else {
                    if (i - dp[i-1] > 0 && s[i - 1 - dp[i-1]] == '(') {
                        dp[i] = ((i - 2 - dp[i-1] >= 0) ? dp[i - 2 - dp[i-1]] : 0) + dp[i-1] + 2;
                    }
                }
                max = std::max(max, dp[i]);
            }
        }
        return max;
    }

    // stack1 o(n), o(n)
    int longestValidParentheses1(const string& s) {
        stack<int> st;
        int  max = 0;
        for (auto &c : s) {
            if (c == '(') st.push(-1);
            else {
                int new_el = 0;
                while (!st.empty() && st.top() != -1)
                    new_el += st.top(); st.pop();

                if (st.empty())
                    max = std::max(max, new_el);
                else {
                    st.pop(); st.push(new_el + 2);
                }
            }
        }
        int cur = 0;
        while (!st.empty()) {
            if (st.top() != -1)
                cur += st.top();
            else {
                max = max = std::max(max, cur);
                cur = 0;
            }
            st.pop();

        }
        max = max = std::max(max, cur);
        return max;
    }
};
#endif //CPP_TRAINING_32_LONGEST_VALID_PARENTHESES_H
