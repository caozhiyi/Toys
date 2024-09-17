/*
给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
*/
// Definition for a binary tree node.

#include <vector>
#include <unordered_map>

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
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map_[inorder[i]] = i;
        }
        
        return subBuildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* subBuildTree(std::vector<int>& inorder, std::vector<int>& postorder,
        int inorder_left, int inorder_right,
        int postorder_left, int postorder_right) {
        
        if (postorder_left > postorder_right) {
            return nullptr;
        }
        
        // build root node 
        TreeNode* root = new TreeNode(postorder[postorder_right]);

        // find left tree node count
        int root_index_in_inorder = inorder_map_[postorder[postorder_right]];
        int left_count = root_index_in_inorder - inorder_left;

        // build left and right tree
        root->left = subBuildTree(inorder, postorder,
            inorder_left, root_index_in_inorder - 1,
            postorder_left, postorder_left + left_count - 1);
        root->right = subBuildTree(inorder, postorder,
            root_index_in_inorder + 1, inorder_right, 
            postorder_left + left_count, postorder_right - 1);

        return root;
    }

private:
    std::unordered_map<int, int> inorder_map_; // value->index
};