#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> ret;
        generate("", n, n, ret);
        return ret;
    }

    void generate(std::string str, int left, int right, std::vector<std::string> &res) {
        if (left == 0 && right == 0) {
            res.push_back(str);
        }

        if (left > 0) {
            generate(str + "(", left - 1, right, res);   
        }
        if (right > 0 && left < right) {
            generate(str + ")", left, right - 1, res);   
        }
    }
};