/*
Given the root of a binary tree, return the average value of the nodes on each level in the form of an array.
Answers within 10-5 of the actual answer will be accepted.
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
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> ret;
        if (!root) {
            return ret;
        }
        
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            int size = queue.size();
            double sum = 0;
            int count = size;
            while (size > 0) {
                size--;

                auto node = queue.front();
                queue.pop();

                sum += node->val;

                if (node->right) {
                    queue.push(node->right);
                }
                if (node->left) {
                    queue.push(node->left);
                }
            }
            ret.push_back(sum / count);
        }
        return ret;
    }
};