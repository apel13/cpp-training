//
// Created by apel on 10.12.2020.
//

#ifndef CPP_TRAINING_103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H
#define CPP_TRAINING_103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H

// problem:
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class Solution {
public:
    vector <vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector <vector<int>> res;
        if (root == nullptr) return res;
        int h = maxH(root, 0);
        res.resize(h);
        helper(root, res, 0);

        for (size_t i = 1; i < h; i += 2) {
            std::reverse(res[i].begin(), res[i].end());
        }
        return res;
    }

    void helper(TreeNode *node, vector <vector<int>> &res, int h)
    {
        if (node == nullptr) return;
        res[h].push_back(node->val);
        helper(node->left, res, h + 1);
        helper(node->right, res, h + 1);
    }

    int maxH(TreeNode *node, int h)
    {
        if (node == nullptr) return h;
        return max(maxH(node->left, h + 1), maxH(node->right, h + 1));
    }

};

#endif //CPP_TRAINING_103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H
