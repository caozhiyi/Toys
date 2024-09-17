/*
给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
每条从根节点到叶节点的路径都代表一个数字：

例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
计算从根节点到叶节点生成的 所有数字之和 。
叶节点 是指没有子节点的节点。
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

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int ret = 0;
        sumNumbers(root, 0, ret);
        return ret;
    }

    void sumNumbers(TreeNode* root, int cur_value, int& ret_value) {
        cur_value = cur_value * 10 + root->val;
        
        if (root->left == nullptr && root->right == nullptr) {
            ret_value += cur_value;
            return;
        }
        
        if (root->left) {
            sumNumbers(root->left, cur_value, ret_value);
        }
        if (root->right) {
            sumNumbers(root->right, cur_value, ret_value);
        }
    }
};