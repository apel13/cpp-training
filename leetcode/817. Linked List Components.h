#pragma once

// problem:
// https://leetcode.com/problems/linked-list-components/


class Solution {
public:
    int numComponents(ListNode* head, vector<int>& g) {
        unordered_set<int> s(
            make_move_iterator(g.begin()), 
            make_move_iterator(g.end()));
        
        int ans = 0;
        while (head != nullptr) {
            if (s.count(head->val) && (head->next == nullptr || !s.count(head->next->val))) {
                ans++;
            }
            head = head->next;
        }
        return ans;
    }
};