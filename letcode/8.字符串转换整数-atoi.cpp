/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <string>
// @lc code=start
class Solution {
public:
    int myAtoi(std::string s) {
        static int max = std::numeric_limits<int>::max() / 10;
        static int min = std::numeric_limits<int>::min() / 10;

        int ret = 0;
        bool low_zero = false;
        int index = 0;
        for (; index < s.length(); index++) {
            if (s[index] == '-') {
                low_zero = true;
                index++;
                break;

            } else if (s[index] == '+') {
                index++;
                break;

            } else if (s[index] <= '9' && s[index] >= '0') {
                break;

            } else if (s[index] != ' ') {
                return ret;
            } 
        }

        for (; index < s.length(); index++) {
            if (s[index] <= '9' && s[index] >= '0') {
                if (max < ret) {
                    return std::numeric_limits<int>::max();
                }
                if (min > ret) {
                    return std::numeric_limits<int>::min();
                }
                ret = ret * 10;
                int temp = s[index] - '0';
                if (low_zero) {
                    if (ret < (std::numeric_limits<int>::min() + temp)) {
                        return std::numeric_limits<int>::min();
                    }
                } else {
                    if (ret > (std::numeric_limits<int>::max() - temp)) {
                        return std::numeric_limits<int>::max();
                    }
                }
                
                if (low_zero) {
                    ret -= temp;
                } else {
                    ret += temp;
                }
            } else {
                return ret;
            }
        }
        return ret;
    }
};
// @lc code=end

