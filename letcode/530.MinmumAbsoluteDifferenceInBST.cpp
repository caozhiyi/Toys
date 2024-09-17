/*
Given the root of a Binary Search Tree (BST),
return the minimum absolute difference between the values of any two different nodes in the tree.
*/
#include <queue>
#include <limits>

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
    int getMinimumDifference(TreeNode* root) {
        int ret = std::numeric_limits<int>::max();
        int pre = std::numeric_limits<int>::min();
        std::queue<int> queue;
        getMinimumDifference(root, pre, ret);
        return ret;
    }

    void getMinimumDifference(TreeNode* root, int& pre, int& min) {
        if (!root) {
            return;
        }
        
        if (root->left) {
            getMinimumDifference(root->left, pre, min);
        }
        
        if (pre != std::numeric_limits<int>::min()) {
            int cur_min = root->val - pre;
            if (cur_min < min) {
                min = cur_min;
            }
        }
        pre = root->val;

        if (root->right) {
            getMinimumDifference(root->right, pre, min);
        }
    }
};