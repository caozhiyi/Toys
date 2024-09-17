/*
Given the root of a binary tree, return the level order traversal of its nodes' values.
 (i.e., from left to right, level by level).
*/

#include <queue>
#include <vector>
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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ret;
        if (!root) {
            return ret;
        }
        
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            int size = queue.size();
            std::vector<int> cur_level;
            cur_level.reserve(size);
            while (size > 0) {
                size--;

                auto node = queue.front();
                queue.pop();

                cur_level.push_back(node->val);

                if (node->left) {
                    queue.push(node->left);
                }

                if (node->right) {
                    queue.push(node->right);
                }
            }
            ret.emplace_back(std::move(cur_level));
        }
        return ret;
    }
};