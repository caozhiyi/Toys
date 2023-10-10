/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <unordered_map>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> ret;
        ret.resize(2);
        std::unordered_map<int, int> map;
        for (size_t i = 0; i < nums.size(); i++) {
            int left = target - nums[i];
            auto iter = map.find(left);
            if (iter != map.end()) {
                ret[0] = iter->second;
                ret[1] = i;
                break;
            }
            map[nums[i]] = i;
        }
        return std::move(ret);
    }
};
// @lc code=end

