/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/
#include <algorithm>
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
private:
    bool first;
public:
    bool isValidBST(TreeNode* root) {
        first = true;
        int pre = std::numeric_limits<int>::min();
        return isValidBST(root, pre);
    }

    bool isValidBST(TreeNode* root, int& pre) {
        if (!root) {
            return true;
        }
        
        if (root->left) {
            if (!isValidBST(root->left, pre)) {
                return false;
            }
        }
        
        if (!first) {
            if (root->val <= pre) {
                return false;
            }
        }
        first = false;
        pre = root->val;

        if (root->right) {
            if (!isValidBST(root->right, pre)) {
                return false;
            }
        }
        return true;
    }
};