/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T 
that has both p and q as descendants (where we allow a node to be a descendant of itself).”
*/
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#include <list>

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::list<TreeNode*> p_list;
        std::list<TreeNode*> q_list;
        findOnePath(root, p, p_list);
        findOnePath(root, q, q_list);
        
        TreeNode* prev = nullptr;
        for (auto p_iter = p_list.begin(), q_iter = q_list.begin();
            p_iter != p_list.end() && q_iter != q_list.end();
            p_iter++, q_iter++) {
            
            if (*p_iter == *q_iter) {
                prev = *p_iter;
                continue;
            }
            break;
        }
        
        return prev;
    }

    bool findOnePath(TreeNode* root, TreeNode* node, std::list<TreeNode*>& node_path) {
        if (!root) {
            return false;
        }
        
        if (root == node) {
            node_path.push_front(root);
            return true;
        }
        
        if (root->left) {
            if (findOnePath(root->left, node, node_path)) {
                node_path.push_front(root);
                return true;
            }
        }
        
        if (root->right) {
            if (findOnePath(root->right, node, node_path)) {
                node_path.push_front(root);
                return true;
            }
        }
        return false;
    }
};