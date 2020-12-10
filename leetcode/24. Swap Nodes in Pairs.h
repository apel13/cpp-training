//
// Created by apel on 10.12.2020.
//

#ifndef CPP_TRAINING_24_SWAP_NODES_IN_PAIRS_H
#define CPP_TRAINING_24_SWAP_NODES_IN_PAIRS_H

// problem:
// https://leetcode.com/problems/swap-nodes-in-pairs/

class Solution {
public:
    ListNode* checkK(ListNode* root, int k) {
        if (root == nullptr) return nullptr;
        while(--k) {
            if (root->next == nullptr) return nullptr;
            root = root->next;
        }
        return root;
    }

    ListNode* swapPairs(ListNode* head, int k = 2) {
        ListNode* new_head = head;
        ListNode* cur = head;

        ListNode* first = head;
        ListNode* last;

        ListNode* pre = nullptr;
        ListNode* post;

        while (true) {
            last = checkK(cur, k);
            if (last == nullptr) {
                if (pre != nullptr)
                    pre->next = cur;
                break;
            } else {
                post = last->next;

                first = reverseK(cur, k);
                if (pre == nullptr)
                    new_head = first;
                else
                    pre->next = first;

                pre = cur;
                cur = post;
            }
        }
        return new_head;
    }

    ListNode* reverseK(ListNode* root, int k) {
        if (k == 1) return root;
        if (k == 2) {
            ListNode* cur = root->next;
            cur->next = root;
            return cur;
        }
        k-=2;
        ListNode* last3 = root;
        ListNode* last2 = root->next;
        ListNode* last1 = last2->next;

        while(k--) {
            last2->next = last3;
            last3 = last2;
            last2 = last1;
            last1 = last1->next;
        }
        last2->next = last3;
        return last2;
    }
};

#endif //CPP_TRAINING_24_SWAP_NODES_IN_PAIRS_H
