/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/

#include <vector>
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }

    int binarySearch(std::vector<int>& nums, int start, int end, int target) {
        if (start > end) {
            return -1;
        }
        
        int target_index = (start + end) / 2;
        if (target > nums[target_index]) {
            if (nums[target_index] < nums[start] && target >= nums[start]) {
                return binarySearch(nums, start, target_index - 1, target);

            } else {
                return binarySearch(nums, target_index + 1, end, target);
            }
            
        } else if (target < nums[target_index]) {
            if (nums[target_index] > nums[end] && target <= nums[end]) {
                return binarySearch(nums, target_index + 1, end, target);

            } else {
                return binarySearch(nums, start, target_index - 1, target);
            }

        } else {
            return target_index;
        }
    }
};

class Solution1 {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int ret = -1;
        while (left <= right) {
            int target_index = (left + right) / 2;
            if (target > nums[target_index]) {
                if (nums[target_index] < nums[0] && target >= nums[0]) {
                    right = target_index - 1;
                } else {
                    left = target_index + 1;
                }

            } else if (target < nums[target_index]) {
                if (nums[target_index] > nums[nums.size() - 1] && target <= nums[nums.size() - 1]) {
                    left = target_index + 1;

                } else {
                    right = target_index - 1;
                }

            } else {
                ret = target_index;
                break;
            }
        }
        
        return ret;
    }
};