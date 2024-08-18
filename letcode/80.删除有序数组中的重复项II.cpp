/*
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/
#include <vector>
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int new_index = 0;
        int repeat_times = 1;
        int repeat_value = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            if (repeat_value == nums[i]) {
                repeat_times++;
                if (repeat_times <= 2) {
                    new_index++;
                    if (new_index < i) {
                        nums[new_index] = nums[i];
                    }
                }

            } else {
                new_index++;
                repeat_value = nums[i];
                repeat_times = 1;
                if (new_index < i) {
                    nums[new_index] = nums[i];
                }

            }
        }
        return new_index + 1;
    }
};