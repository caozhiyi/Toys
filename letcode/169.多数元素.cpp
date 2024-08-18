/*
给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素
*/
#include <vector>
#include <algorithm>
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};