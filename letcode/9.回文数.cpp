/*
Given an integer x, return true if x is a 
palindrome , and false otherwise.
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

#include <string>
class Solution {
public:
    bool isPalindrome(int x) {
        std::string str = std::to_string(x);
        for (int i = 0; i < str.size() / 2; i++) {
            if (str[i] != str[str.size() - i -1]) {
                return false;
            }
        }
        return true;
    }
};
