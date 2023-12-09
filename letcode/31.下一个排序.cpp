#include <vector>
#include <limits>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) {
            return;
        }
        
        if (isBigOrder(nums)) {
            reverseVec(nums);
            return;
        }
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            int target = std::numeric_limits<int>::max();
            int target_index = -1;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] > nums[i] && nums[j] < target) {
                    target = nums[j];
                    target_index = j;
                }
            }
            if (target_index != -1) {
                int temp = nums[target_index];
                nums[target_index] = nums[i];
                nums[i] = temp;

                sort(nums, i + 1);
                break;
            }
        }
    }

    void reverseVec(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int temp = nums[right];
            nums[right] = nums[left];
            nums[left] = temp;
            left++;
            right--;
        }
    }

    bool isBigOrder(std::vector<int>& nums) {
        bool big_order = true;
        for (size_t i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                big_order = false;
                break;
            }
        }
        return big_order;
    }

    void sort(std::vector<int>& nums, int index) {
        auto iter = nums.begin();
        for (size_t i = 0; i < index; i++) {
            iter++;
        }
        
        std::sort(iter, nums.end());
    }
};