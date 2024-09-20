/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> ret;
        generate("", n, n, ret);
        return ret;
    }

    void generate(std::string str, int left, int right, std::vector<std::string>& ret) {
        if (left == 0 && right == 0) {
            ret.push_back(str);
        }

        if (left > 0) {
            generate(str + "(", left - 1, right, ret);   
        }
        if (right > 0 && left < right) {
            generate(str + ")", left, right - 1, ret);   
        }
    }
};