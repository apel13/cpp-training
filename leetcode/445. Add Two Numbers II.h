#pragma once 

// problem:
// https://leetcode.com/problems/add-two-numbers-ii/ 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* cur = nullptr;
        int shift = 0;
        while (!s1.empty() && !s2.empty()) {
            int tmp = s1.top() + s2.top() + shift;
            s1.pop(); s2.pop();

            cur = new ListNode(tmp % 10, cur);
            shift = tmp / 10;
        }
        while (!s1.empty()) {
            int tmp = s1.top() + shift;
            s1.pop();

            cur = new ListNode(tmp % 10, cur);
            shift = tmp / 10;
        }
        while (!s2.empty()) {
            int tmp = s2.top() + shift;
            s2.pop();
            cur = new ListNode(tmp % 10, cur);
            shift = tmp / 10;
        }
        if (shift != 0) 
            cur = new ListNode(shift, cur);
        return cur;
    }
};