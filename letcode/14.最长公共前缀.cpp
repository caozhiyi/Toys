/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include <vector>
#include <string>
// @lc code=start
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string ret;
        int index = 0;
        bool run = true;
        while (run) {
            char temp;
            for (size_t i = 0; i < strs.size(); i++) {
                if (index >= strs[i].size()) {
                    run = false;
                    break;
                }
                
                if (i == 0) {
                    temp = strs[i][index];
                    continue;
                }

                if (temp != strs[i][index]) {
                    run = false;
                    break;
                }
            }
            if (run) {
                ret = ret + temp;
            }
            index++;
        }
        return ret;
    }
};
// @lc code=end

