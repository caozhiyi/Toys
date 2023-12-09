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
                
            }
             
        }
        
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