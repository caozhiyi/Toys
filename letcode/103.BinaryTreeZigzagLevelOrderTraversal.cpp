/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).
*/

#include <queue>
#include <vector>
#include <algorithm>
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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ret;
        if (!root) {
            return ret;
        }
        
        std::queue<TreeNode*> queue;
        queue.push(root);
        bool from_left_to_right = true;
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
            if (from_left_to_right) {
                std::reverse(cur_level.begin(), cur_level.end());
            }
            from_left_to_right = !from_left_to_right;
            
            ret.emplace_back(std::move(cur_level));
        }
        return ret;
    }
};