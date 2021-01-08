//
// Created by apel on 08.01.2021.
//

#ifndef CPP_TRAINING_148_SORT_LIST_H
#define CPP_TRAINING_148_SORT_LIST_H

// problem:
// https://leetcode.com/problems/sort-list/

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* mid = split(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }

    ListNode* split(ListNode* node) {
        ListNode* mid_prev = nullptr;
        while (node && node->next) {
            mid_prev = (mid_prev) ? mid_prev->next : node;
            node = node->next->next;
        }
        ListNode* ans = mid_prev->next;
        mid_prev->next = nullptr;
        return ans;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode * ans = new ListNode();
        ListNode * last = ans;
        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                last->next = left;
                left = left->next;
            } else {
                last->next = right;
                right = right->next;
            }
            last = last->next;
        }
        last->next = right ? right : left;
        return ans->next;
    }
};

#endif //CPP_TRAINING_148_SORT_LIST_H
