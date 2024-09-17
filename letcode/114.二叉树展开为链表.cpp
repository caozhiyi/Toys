/*
给你二叉树的根结点 root ，请你将它展开为一个单链表：
展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。
*/

#include <queue>

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
    void flatten(TreeNode* root) {
        std::queue<TreeNode*> node_queue;
        flatten(root, node_queue);

        TreeNode* prev = nullptr;
        while (!node_queue.empty()) {
            auto node = node_queue.front();
            node_queue.pop();
            node->left = nullptr;

            if (prev == nullptr) {
                prev = node;
                continue;
            }
            
            prev->right = node;
            prev = node;
        }
    }

    void flatten(TreeNode* root, std::queue<TreeNode*>& node_queue) {
        if (root) {
            node_queue.push(root);
        } else {
            return;
        }
        
        flatten(root->left, node_queue);
        flatten(root->right, node_queue);
    }
};