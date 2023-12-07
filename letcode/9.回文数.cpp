/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include <limits>
// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        return x == revNum(x);
    }

    int revNum(int x) {
        static int max = std::numeric_limits<int>::max() / 10;
        static int min = std::numeric_limits<int>::min() / 10;
        int ret = 0;
        while (x != 0) {
            if (ret > max || ret < min) {
                return -1;
            }
            int temp = x % 10;
            x = x / 10;
            ret = ret * 10 + temp;
        }
        return ret;
        
    }
};
// @lc code=end

