//
// Created by apel on 10.12.2020.
//

#ifndef CPP_TRAINING_23_MERGE_K_SORTED_LISTS_H
#define CPP_TRAINING_23_MERGE_K_SORTED_LISTS_H

// problem:
// https://leetcode.com/problems/product-of-array-except-self/

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr)
    {}

    ListNode(int x) : val(x), next(nullptr)
    {}

    ListNode(int x, ListNode *next) : val(x), next(next)
    {}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return nullptr;
        if (n == 1) return lists[0];

        auto* head = new ListNode();
        ListNode* cur_node = head;

        auto s_cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, std::vector<ListNode*>, decltype(s_cmp)> pq(s_cmp);

        for (size_t i = 0; i < n; ++i) {
            if (lists[i] != nullptr)
                pq.push(lists[i]);
        }
        while (!pq.empty()) {
            auto d = pq.top();pq.pop();
            cur_node->next = new ListNode(d->val);
            cur_node = cur_node->next;
            if (d->next != nullptr)
                pq.push(d->next);

        }
        return head->next;
    }
};

#endif //CPP_TRAINING_23_MERGE_K_SORTED_LISTS_H
