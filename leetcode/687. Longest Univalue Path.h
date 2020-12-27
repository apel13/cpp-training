//
// Created by apel on 26.12.2020.
//

#ifndef CPP_TRAINING_687_LONGEST_UNIVALUE_PATH_H
#define CPP_TRAINING_687_LONGEST_UNIVALUE_PATH_H

// problem:
// https://leetcode.com/problems/longest-univalue-path/

class Solution {
public:
    int longestUnivaluePath(TreeNode *root) {
        max = 0;
        helper(root);
        return max;
    }

    int helper(TreeNode *node) {
        if (node == nullptr) return 0;
        int l = helper(node->left);
        int r = helper(node->right);
        l = (node->left != nullptr && node->left->val == node->val) ? l + 1 : 0;
        r = (node->right != nullptr && node->right->val == node->val) ? r + 1 : 0;
        max = std::max(max, l + r);
        return std::max(l, r);
    }
    int max;
};

#endif //CPP_TRAINING_687_LONGEST_UNIVALUE_PATH_H
