/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include <string>
// @lc code=start
class Solution {
public:
    enum Bit {
        One     = 1,
        Five    = 2,
        Ten     = 3,
        Fifty   = 4,
        Han     = 5,
        FiveHan = 6,
        Sou     = 7,
    };
    int romanToInt(std::string s) {
        Bit bit = One;
        int ret = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            switch (s[i])
            {
            case 'I':
                if (bit == Five || bit == Ten) {
                    ret -= 1;
                
                } else {
                    ret += 1;
                }
                break;

            case 'V':
                ret += 5;
                bit = Five;
                break;

            case 'X':
                if (bit == Fifty || bit == Han) {
                    ret -= 10;
                } else {
                    ret += 10;
                }
                bit = Ten;
                break;

            case 'L':
                ret += 50;
                bit = Fifty;
                break;

            case 'C':
                if (bit == FiveHan || bit == Sou) {
                    ret -= 100;
                } else {
                    ret += 100;
                }
                bit = Han;
                break;

            case 'D':
                ret += 500;
                bit = FiveHan;
                break;

            case 'M':
                ret += 1000;
                bit = Sou;
                break;

            default:
                return - 1;
            }
        }
        return ret;
    }
};
// @lc code=end

