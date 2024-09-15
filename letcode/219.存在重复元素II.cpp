/*
给你一个整数数组 nums 和一个整数 k ，
判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 
且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。
*/

#include <vector>
#include <unordered_map>
class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            auto iter = map.find(nums[i]);
            if (iter != map.end()) {
                if (std::abs(iter->second - i) <= k) {
                    return true;
                }
            }
            map[nums[i]] = i;
        }
        return false;
    }
};