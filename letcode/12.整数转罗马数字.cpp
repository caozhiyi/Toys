/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
#include <unordered_map>
#include <string>
// @lc code=start
class Solution {
private:
    enum Bit {
        One = 0x1,
        Ten = 0x2,
        Han = 0x4,
        Sou = 0x8,
    };
    static bool _lm_num_init;
    static std::unordered_map<int, std::string> _lm_num;

public:
    Solution() {
        if (!_lm_num_init) {
            _lm_num_init = true;
            _lm_num[1 << 4 | One] = "I";
            _lm_num[2 << 4 | One] = "II";
            _lm_num[3 << 4 | One] = "III";
            _lm_num[4 << 4 | One] = "IV";
            _lm_num[5 << 4 | One] = "V";
            _lm_num[6 << 4 | One] = "VI";
            _lm_num[7 << 4 | One] = "VII";
            _lm_num[8 << 4 | One] = "VIII";
            _lm_num[9 << 4 | One] = "IX";
            _lm_num[1 << 4 | Ten] = "X";
            _lm_num[2 << 4 | Ten] = "XX";
            _lm_num[3 << 4 | Ten] = "XXX";
            _lm_num[4 << 4 | Ten] = "XL";
            _lm_num[5 << 4 | Ten] = "L";
            _lm_num[6 << 4 | Ten] = "LX";
            _lm_num[7 << 4 | Ten] = "LXX";
            _lm_num[8 << 4 | Ten] = "LXXX";
            _lm_num[9 << 4 | Ten] = "XC";
            _lm_num[1 << 4 | Han] = "C";
            _lm_num[2 << 4 | Han] = "CC";
            _lm_num[3 << 4 | Han] = "CCC";
            _lm_num[4 << 4 | Han] = "CD";
            _lm_num[5 << 4 | Han] = "D";
            _lm_num[6 << 4 | Han] = "DC";
            _lm_num[7 << 4 | Han] = "DCC";
            _lm_num[8 << 4 | Han] = "DCCC";
            _lm_num[9 << 4 | Han] = "CM";
            _lm_num[1 << 4 | Sou] = "M";
            _lm_num[2 << 4 | Sou] = "MM";
            _lm_num[3 << 4 | Sou] = "MMM";
        }
    }

    std::string intToRoman(int num) {
        int bit = 1;
        std::string ret;
        while (num > 0) {
            int temp = num % 10;
            num = num / 10;
            auto iter = _lm_num.find(temp << 4 | bit);
            if (iter != _lm_num.end()) {
                ret = iter->second + ret;
            }
            bit = bit << 1;
        }
        return ret;
    }
};
bool Solution::_lm_num_init = false;
std::unordered_map<int, std::string> Solution::_lm_num;
// @lc code=end

