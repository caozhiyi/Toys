/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced
binary search tree.
*/
// Definition for a binary tree node.
#include <vector>

using namespace std;

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }

        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        
        if (left == right) {
            TreeNode* node = new TreeNode(nums[left]);
            return node;
        }
        
        int middle = (right + left) / 2;
        TreeNode* node = new TreeNode(nums[middle]);
        node->left = sortedArrayToBST(nums, left, middle - 1);
        node->right = sortedArrayToBST(nums, middle + 1, right);
        return node;
    }
};