/*
二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。
同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
路径和 是路径中各节点值的总和。
给你一个二叉树的根节点 root ，返回其 最大路径和 。
*/
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <algorithm>

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_value = -999999999;
        maxGain(root, max_value);
        return max_value;
    }

    int maxGain(TreeNode* root, int& max_value) {
        if (!root) {
            return 0;
        }
        
        int left_max_value = std::max(maxGain(root->left, max_value), 0);
        int right_max_value = std::max(maxGain(root->right, max_value), 0);

        int cur_value = root->val + left_max_value + right_max_value;
        if (cur_value > max_value) {
            max_value = cur_value;
        }
        
        return root->val + std::max(left_max_value, right_max_value);
    }
};