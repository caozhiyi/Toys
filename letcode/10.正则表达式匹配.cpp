/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
#include <string>
// @lc code=start
class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int s_index = 0;
        int p_index = 0;
        char prev_char = p[p_index];
        char all = '#';
        while (p_index < p.length() && s_index < s.length()) {
            if (p[p_index] == '.') {
                s_index++;

            } else if (p[p_index] == '*') {
                while ((s[s_index] == prev_char || prev_char == '.') && s_index < s.length()) {
                    all = s[s_index];
                    s_index++;
                }
                
            } else {
                if (s[s_index] == p[p_index]) {
                    s_index++;
                }
            }
            prev_char = p[p_index];
            p_index++;
        }

        int temp_p_index = p_index;
        while (temp_p_index < p.length()) {
            if (p[temp_p_index] == '*') {
                p_index += 2;
            }
            temp_p_index++;
        }
        if (p_index == p.length() - 1 && p[p_index] == all) {
            p_index++;
        }
        
        return p_index >= p.length() && s_index == s.length();
    }
};
// @lc code=end

