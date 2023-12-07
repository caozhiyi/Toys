/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] N 字形变换
 */
#include <vector>
#include <string>
// @lc code=start
class Solution {
public:
    enum State {
        Down,
        Up,
    };
    std::string convert(std::string s, int numRows) {
        std::vector<std::string> dict;
        dict.resize(numRows);
        int line = 0;
        State state = Down;
        for (size_t i = 0; i < s.length();i++) {
            if (state == Down) {
                dict[line] += s[i];
                line++;
                if (line >= numRows - 1) {
                    line = numRows - 1;
                    state = Up;
                };
                
            } else {
                dict[line] += s[i];
                line--;
                if (line <= 0) {
                    line = 0;
                    state = Down;
                };
            }
        }
        
        std::string ret;
        for (size_t i = 0; i < dict.size(); i++) {
            ret += dict[i];
        }
        return ret;
    }
};
// @lc code=end

