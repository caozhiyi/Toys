/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <vector>
// @lc code=start
class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int temp = 0;
            if (height[left] < height[right]) {
                temp = (right - left) * height[left];
                left++;
            } else {
                temp = (right - left) * height[right];
                right--;
            }
            
            if (max < temp) {
                max = temp;
            }
        }
        
        return max;
    }
};
// @lc code=end

