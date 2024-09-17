/*
Given the root of a binary tree, imagine yourself standing on the right side of it,
return the values of the nodes you can see ordered from top to bottom.
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
#include <vector>

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> ret;
        if (!root) {
            return ret;
        }
        
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            int size = queue.size();
            while (size > 0) {
                size--;

                auto node = queue.front();
                queue.pop();

                if (size == 0) {
                    ret.push_back(node->val);
                }
                
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }
        }
        return ret;
    }
};