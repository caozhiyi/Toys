/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        if (nums.size() == 2) {
            return nums[0] > nums[1] ? nums[0] : nums[1];
        }
        
        int first = nums[0];
        int second = nums[1];

        for (int i = 2; i < nums.size(); i++) {
            int temp = max(second, first + nums[i]);
            first = max(first, second);
            second = temp;
        }
        return second;
    }
};

// 数据的含义 index value index->房屋 value最大钱数
// 递推公式 cur value = max(index - 1, cur value + index - 2)
// 初始化 
// 遍历顺序 
// 打印数组