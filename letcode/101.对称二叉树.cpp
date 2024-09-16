/*
给你一个二叉树的根节点 root ， 检查它是否轴对称。
*/
//Definition for a binary tree node.
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr && node2 == nullptr) {
            return true;

        } else if (node1 == nullptr || node2 == nullptr) {
            return false;

        } else if (node1->val != node2->val) {
            return false;
        }
        return isSymmetric(node1->left, node2->right) && isSymmetric(node1->right, node2->left);
        
    }
};