/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <vector>
#include <string>
#include <algorithm>

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        int size = nums.size();
        if (size < 3)   return {};          // 特判

        std::vector<std::vector<int>>res;  // 保存结果（所有不重复的三元组）
        std::sort(nums.begin(), nums.end());// 排序（默认递增）
        for (int i = 0; i < size; i++) {     // 固定第一个数，转化为求两数之和
            if (nums[i] > 0)    
                return res; // 第一个数大于 0，后面都是递增正数，不可能相加为零了

            // 去重：如果此数已经选取过，跳过
            if (i > 0 && nums[i] == nums[i-1])  
                continue;
            // 双指针在nums[i]后面的区间中寻找和为0-nums[i]的另外两个数
            int left = i + 1;
            int right = size - 1;
            while (left < right) {
                if (nums[left] + nums[right] > -nums[i])
                    right--;    // 两数之和太大，右指针左移
                else if (nums[left] + nums[right] < -nums[i])
                    left++;     // 两数之和太小，左指针右移
                else {
                    // 找到一个和为零的三元组，添加到结果中，左右指针内缩，继续寻找
                    res.push_back(std::vector<int>{nums[i], nums[left], nums[right]});

                    left++;
                    right--;
                    // 去重：第二个数和第三个数也不重复选取
                    while (left < right && nums[left] == nums[left-1])  left++;
                    while (left < right && nums[right] == nums[right+1]) right--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

