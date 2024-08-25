/*
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
返回容器可以储存的最大水量。
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

