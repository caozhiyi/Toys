/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] N 字形变换
 */
/*
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
请你实现这个将字符串进行指定行数变换的函数：
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

