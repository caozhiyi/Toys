/*
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点
*/

//Definition for a binary tree node.
#include <vector>
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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        TreeNode* root = new TreeNode;
        auto iter1 = preorder.begin();
        auto iter2 = preorder.begin();
        for (; iter1 != preorder.end(); iter1++) {
            root->val = *iter1;

            for (auto iter = iter2; iter != preorder.end(); iter++) {
                if (*iter != root->val) {
                    continue;
                }
            }
        }
    }

    TreeNode* buildLeft(std::vector<int>::iterator inorder_start, std::vector<int>::iterator inorder_end, std::vector<int>::iterator& preorder_iter) {
        if (inorder_start == inorder_end) {
            TreeNode* root = new TreeNode(*inorder_start);
            return root;
        }
        
    }

    TreeNode* buildRight(std::vector<int>::iterator inorder_start, std::vector<int>::iterator inorder_end) {
        if (inorder_start == inorder_end) {
            TreeNode* root = new TreeNode(*inorder_start);
            return root;
        }
        
    }
};