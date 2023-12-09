#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int target_index = nums.size();

        while (left <= right) {
            int temp_index = (left + right) / 2;
            if (target > nums[temp_index]) {
                left = temp_index + 1;

            } else if (target <= nums[temp_index]) {
                right = temp_index - 1;
                target_index = temp_index;
            }
        }
        
        return target_index;
    }
};