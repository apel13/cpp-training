//
// Created by apel on 08.01.2021.
//

#ifndef CPP_TRAINING_147_INSERTION_SORT_LIST_H
#define CPP_TRAINING_147_INSERTION_SORT_LIST_H

// problem:
// https://leetcode.com/problems/sort-list/

class Solution {
public:
    // bad time
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* current = head;
        ListNode* next, *prev;
        while (current != nullptr) {
            prev = dummy;

            while (prev->next && prev->next->val < current->val)
                prev = prev->next;

            next = current->next;
            current->next = prev->next;
            prev->next = current;
            current = next;
        }
        return dummy->next;
    }

    //bad mem
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* current_node = head;

        while (current_node->next) {
            if (current_node->val > current_node->next->val) {
                ListNode * inserted = current_node->next;
                current_node->next = current_node->next->next;
                head = insert(head, inserted);
            } else
                current_node = current_node->next;
        }
        return head;
    }

    ListNode* insert(ListNode* head, ListNode* inserted_node) {
        if (inserted_node->val < head->val) {
            inserted_node->next = head;
            return inserted_node;
        }
        ListNode* last = head;
        while (last->next && last->next->val < inserted_node->val) {
            last = last->next;
        }
        inserted_node->next=last->next;
        last->next=inserted_node;
        return head;
    }
};

#endif //CPP_TRAINING_147_INSERTION_SORT_LIST_H
