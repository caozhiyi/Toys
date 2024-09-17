/*
给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。
判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。
叶子节点 是指没有子节点的节点。
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        
        targetSum = targetSum - root->val;
        if (targetSum == 0 && root->left == nullptr && root->right == nullptr) {
            return true;
        }
        
        if (root->left) {
            if (hasPathSum(root->left, targetSum)) {
                return true;
            }
        }

        if (root->right) {
            if (hasPathSum(root->right, targetSum)) {
                return true;
            }
        }
        
        return false;
    }
};