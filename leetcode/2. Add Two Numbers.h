#pragma once 

// problem:
// https://leetcode.com/problems/add-two-numbers/ 

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
        int shift = 0;
        ListNode* ret = new ListNode();
        ListNode* cur = ret;

        while (l1 != nullptr && l2 != nullptr) {
            int tmp = l1->val + l2->val + shift;
            cur->next = new ListNode(tmp % 10);
            cur = cur->next;
            shift = tmp / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
            int tmp = l1->val + shift;
            cur->next = new ListNode(tmp % 10);
            cur = cur->next;
            shift = tmp / 10;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            int tmp = l2->val + shift;
            cur->next = new ListNode(tmp % 10);
            cur = cur->next;
            shift = tmp / 10;
            l2 = l2->next;
        }
        if (shift != 0)
            cur->next = new ListNode(tmp % 10);

        return ret->next;
    }
};