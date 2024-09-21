/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
 */
#include <vector>
// @lc code=start
class Solution1 {
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

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        bool two = len % 2 == 0;
        double left = 0;
        double right = 0;

        int num1_index = 0;
        int num2_index = 0;
        for (int i = 0; i < (len / 2) + 1; i++) {
            if (num1_index < nums1.size() && num2_index < nums2.size()) {
                if (nums1[num1_index] < nums2[num2_index]) {
                    left = right;
                    right = nums1[num1_index];
                    num1_index++;

                } else {
                    left = right;
                    right = nums2[num2_index];
                    num2_index++;
                }
                continue;
            }
            
            if (num1_index < nums1.size()) {
                left = right;
                right = nums1[num1_index];
                num1_index++;
                continue;
            }
            
            if (num2_index < nums2.size()) {
                left = right;
                right = nums2[num2_index];
                num2_index++;
            }
        }
        
        if (two) {
            return (left + right) / 2;
        }
        return right;
    }
};

