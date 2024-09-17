/*
Given the root of a binary search tree, and an integer k,
return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
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
    int kthSmallest(TreeNode* root, int k) {
        int ret = 0;
        kthSmallest(root, k, ret);
        return ret;
    }

    bool kthSmallest(TreeNode* root, int& k, int& ret) {
        if (!root) {
            return true;
        }
        
        if (root->left) {
            if (!kthSmallest(root->left, k, ret)) {
                return false;
            }
        }
        
        k--;
        if (k == 0) {
            ret = root->val;
            return false;
        } 

        if (root->right) {
            if (!kthSmallest(root->right, k, ret)) {
                return false;
            }
        }
        return true;
    }
};