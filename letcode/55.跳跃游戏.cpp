/*
给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。
*/

#include <vector>
class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        return whoCanJump(nums, nums.size() - 1);
    }

    bool whoCanJump(std::vector<int>& nums, int cur_index) {
        if (cur_index == 0) {
            return true;
        }
        
        for (int i = cur_index - 1; i >=0 ; i--) {
            if (nums[i] >= cur_index - i) {
                return whoCanJump(nums, i);
            }
        }
        return false;
    }

    bool canJump1(std::vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }
        
        int max_distance = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (i > max_distance) {
                return false;
            }
            int cur_distance = i + nums[i];
            if (cur_distance > max_distance) {
                max_distance = cur_distance;
            }
        }
        return max_distance >= nums.size() - 1;
    }
};