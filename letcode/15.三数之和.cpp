/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        if (nums.size() < 3) {
            return ret;
        }
        
        std::unordered_set<std::string> unique_set;

        std::sort(nums.begin(), nums.end());

        if (nums[0] > 0 || nums[nums.size() - 1] < 0) {
            return ret;
        }
        
        auto left = nums.begin();
        auto right = nums.end()--;
        while (left != right) {
            int left_value = *left;
            int right_value = *right;
            int target = -(left_value + right_value);
            if (target > 0) {
                right--;

            } else {
                left++;
            }
            
            if (std::binary_search(left, right, target)) {
                std::string unique_str = std::to_string(left_value) +  std::to_string(target)
                 + std::to_string(right_value);
                if (unique_set.find(unique_str) != unique_set.end()) {
                    unique_set.insert(unique_str);
                    ret.emplace_back(std::vector<int>{left_value, target, right_value});
                }
            }
        }
        return ret;
    }
};
// @lc code=end

