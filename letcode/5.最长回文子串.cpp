/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <string>
// @lc code=start
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() < 2) {
            return s;
        }
        
        std::pair<int, int> target;
        target.first = 0;
        target.second = 0;
        int index = 0;
        while (index < s.length()) {
            auto t1 = expand(s, index, index);
            if (t1.second - t1.first > target.second - target.first) {
                target = t1;
            }
            
            auto t2 = expand(s, index, index + 1);
            if (t2.second - t2.first > target.second - target.first) {
                target = t2;
            }
            index++;
        }
        
        
        return s.substr(target.first, target.second - target.first + 1);
    }

    std::pair<int, int> expand(const std::string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return std::make_pair(left+1, right-1);
    }
};
// @lc code=end

