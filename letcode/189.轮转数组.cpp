/*
给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数
*/
#include <string>
#include <vector>
class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        k = k % nums.size();
        if (nums.empty() || k == 0) {
            return;
        }
        
        int* left = &nums[0];
        int* right = &nums[nums.size() - k];
        int* buf = new int[nums.size()];

        if (k < nums.size() - k) {
            memcpy(buf, left, sizeof(int) * (nums.size() - k));
            memcpy(left, right, sizeof(int) * k);
            memcpy(left + k, buf, sizeof(int) * (nums.size() - k));

        } else {
            memcpy(buf, right, sizeof(int) * k);
            memcpy(left + k, left, sizeof(int) * (nums.size() - k));
            memcpy(left, buf, sizeof(int) * k);
        }
        
        delete []buf;
    }
};