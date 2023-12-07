/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include <limits>
// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int max = std::numeric_limits<int>::max() / 10;
        int min = std::numeric_limits<int>::min() / 10;
        int ret = 0;
        while (x != 0) {
            if (ret > max || ret < min) {
                return 0;
            }
            
            int temp = x % 10;
            x = x / 10;
            ret = ret * 10 + temp;
        }
        return ret;
    }
};
// @lc code=end

