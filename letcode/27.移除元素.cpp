#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1 && nums[0] == val) {
            return 0;
        }
        
        int left = 0;
        int right = nums.size() - 1;
        int remove_count = 0;
        while (left <= right) {
            // find left equal value
            while (left <= right) {
                if (nums[left] == val) {
                    remove_count++;
                    break;

                } else {
                    left++;
                }
            }
            // set left value to right
            if (left <= right) {
                nums[left] = nums[right];
                right--;
            }
        }
        return nums.size() - remove_count;
    }
};