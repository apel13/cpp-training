
#pragma once

// problem:
// https://leetcode.com/problems/next-greater-node-in-linked-list/

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ret;
        ListNode* cur = head;
        while (cur != nullptr) {
            ret.push_back(cur->val);
            cur = cur->next;
        }
        stack<int> s;
        for (auto it = ret.rbegin(); it != ret.rend(); ++it) {
            int tmp = *it;
            if (s.empty())
                *it = 0;
            else if (*it >= s.top()) {
                do {
                    s.pop();
                } while (!s.empty() && *it >= s.top());
                *it = s.empty() ? 0 : s.top();
            }
            else 
                *it = s.top();
            s.push(tmp);
        }
        return ret;
    }
};