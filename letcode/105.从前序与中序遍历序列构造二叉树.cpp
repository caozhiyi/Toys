/*
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点
*/

//Definition for a binary tree node.
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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map_[inorder[i]] = i;
        }
        
        return subBuildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* subBuildTree(std::vector<int>& preorder, std::vector<int>& inorder,
        int preorder_left, int preorder_right,
        int inorder_left, int inorder_right) {
        
        if (preorder_left > preorder_right) {
            return nullptr;
        }

        // build root
        TreeNode* root = new TreeNode;
        root->val = preorder[preorder_left];

        // find left tree node count
        int root_index_in_inorder = inorder_map_[preorder[preorder_left]];
        int left_count = root_index_in_inorder - inorder_left;

        root->left = subBuildTree(preorder, inorder,
            preorder_left + 1, preorder_left + left_count,
            inorder_left, root_index_in_inorder - 1);

        root->right = subBuildTree(preorder, inorder,
            preorder_left + left_count + 1, preorder_right,
            root_index_in_inorder + 1, inorder_right);
        return root;
    }
private:
    std::unordered_map<int, int> inorder_map_; // value->index
};