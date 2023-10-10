/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <unordered_map>
#include <string>
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, size_t> temp_map;
        uint32_t max_size = 0;
        uint32_t start = 0;
        for (size_t i = 0; i < s.length(); i++) {
            auto iter = temp_map.find(s[i]);
            if (iter != temp_map.end()) {
                if (max_size < temp_map.size()) {
                    max_size = temp_map.size();
                }
                
                size_t max_index = iter->second;
                for (size_t j = start; j <= max_index; j++) {
                    temp_map.erase(s[j]);
                    start = max_index + 1;
                }
            }
            temp_map[s[i]] = i;
        }
        if (max_size < temp_map.size()) {
            max_size = temp_map.size();
        }
        return max_size;
    }
};
// @lc code=end

