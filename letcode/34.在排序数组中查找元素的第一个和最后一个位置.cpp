/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/
#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int target_index = -1;

        std::vector<int> ret = {-1, -1};
        while (left <= right) {
            int temp_index = (left + right) / 2;
            if (target > nums[temp_index]) {
                left = temp_index + 1;

            } else if (target < nums[temp_index]) {
                right = temp_index - 1;
            
            } else {
                target_index = temp_index;
                break;
            }
        }
        
        if (target_index == -1) {
            return ret;
        }
        
        int temp_index = target_index;
        while (temp_index >= 0 && nums[temp_index] == nums[target_index]) {
            temp_index--;
        }
        ret[0] = temp_index + 1;

        temp_index = target_index;
        while (temp_index < nums.size() && nums[temp_index] == nums[target_index]) {
            temp_index++;
        }
        ret[1] = temp_index - 1;
        return ret;
    }
};


class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int left=-1,right=-1;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i]==target){
                left=i;
                break;
            }
        }    
        for (int i = nums.size()-1; i >=0; i--) {
            if(nums[i]==target){
                right=i;
                break;
            }
        }    
        std::vector<int> ret = {left,right};
        return ret;
    }
};