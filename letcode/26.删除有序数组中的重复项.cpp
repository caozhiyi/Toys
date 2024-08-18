/*
给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，
返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
*/
#include <vector>
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int new_size = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[new_size] != nums[i]) {
                new_size++; // only not equal new_size plus one
                if (new_size != i) {
                    nums[new_size] = nums[i];
                }
            }
        }
        return new_size+1;
    }
};