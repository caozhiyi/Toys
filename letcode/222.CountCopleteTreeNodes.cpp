/*
Given the root of a complete binary tree, return the number of the nodes in the tree.
According to Wikipedia, every level, except possibly the last, 
is completely filled in a complete binary tree, 
and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
Design an algorithm that runs in less than O(n) time complexity.
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

#include <queue>

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        std::queue<TreeNode*> node_queue;
        node_queue.push(root);
        int ret = 0;
        while (!node_queue.empty()) {
            ret++;

            auto node = node_queue.front();
            node_queue.pop();

            if (node->left) {
                node_queue.push(node->left);
            }
            if (node->right) {
                node_queue.push(node->right);
            }
        }
        return ret;
    }
};