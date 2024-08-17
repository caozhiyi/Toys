/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
*/
#include <vector>
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return 1;
        }
        
        int cur_index = 0;
        int last_index = 1;
        for (size_t last_index = 1; last_index < nums.size(); last_index++) {
            if (nums[cur_index] == nums[last_index]) {
                continue;
            }
            cur_index++;
            if (cur_index != last_index) {
                nums[cur_index] = nums[last_index];
            }
        }
        return cur_index + 1;
    }
};