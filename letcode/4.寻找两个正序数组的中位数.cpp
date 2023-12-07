/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */
#include <vector>
// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> temp;
        temp.reserve(nums1.size() + nums2.size());
        int nums1_index = 0;
        int nums2_index = 0;
        while (true) {
            if (nums1[nums1_index] < nums2[nums2_index]) {
                temp.push_back(nums1[nums1_index]);
                nums1_index++;
                if (nums1_index >= nums1.size()) {
                    break;
                }
                
            } else {
                temp.push_back(nums2[nums2_index]);
                nums2_index++;
                if (nums2_index >= nums2.size()) {
                    break;
                }
            }
        }
        for (size_t i = nums1_index; i < nums1.size(); i++) {
            temp.push_back(nums1[i]);
        }
        for (size_t i = nums2_index; i < nums2.size(); i++) {
            temp.push_back(nums2[i]);
        }
        
        int middle_index = temp.size() / 2;
        if (temp.size() % 2 == 0) {
            return (double(temp[middle_index - 1] + temp[middle_index])) / 2;
        } else {
            return double(temp[middle_index]);
        }
    }
};
// @lc code=end

