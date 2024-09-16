/*
给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

注意:不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。
*/
#include <stack>
#include <string>
#include <algorithm>
class Solution {
public:
    int calculate(std::string s) {
        std::stack<std::string> calc_stack;
        std::string cur;

        for (auto iter = s.begin(); iter != s.end(); iter++) {
            if (*iter == '+') {
                if (!cur.empty()) {
                    calc_stack.push(cur);
                    cur.clear();
                }
                calc_stack.push("+");

            }
            else if (*iter == '-') {
                if (!cur.empty()) {
                    calc_stack.push(cur);
                    cur.clear();
                }
                calc_stack.push("-");

            }
            else if (*iter == '(') {
                if (!cur.empty()) {
                    calc_stack.push(cur);
                    cur.clear();
                }
                calc_stack.push("(");

            }
            else if (*iter == ')') {
                if (!cur.empty()) {
                    calc_stack.push(cur);
                    cur.clear();
                }

                int cur_value = 0;
                int item_value = 0;
                while (!calc_stack.empty()) {
                    std::string item = calc_stack.top();
                    calc_stack.pop();
                    if (item != "(") {
                        if (item == "+") {
                            cur_value += item_value;
                            item_value = 0;
                        }
                        else if (item == "-") {
                            cur_value -= item_value;
                            item_value = 0;
                        }
                        else {
                            item_value = std::atoi(item.c_str());
                        }
                        continue;
                    }
                    if (item_value != 0) {
                        cur_value += item_value;
                    }
                    calc_stack.push(std::to_string(cur_value));
                    break;
                }

            }
            else if (*iter == ' ') {
                if (!cur.empty()) {
                    calc_stack.push(cur);
                    cur.clear();
                }

            }
            else {
                cur = cur + *iter;
            }
        }
        if (!cur.empty()) {
            calc_stack.push(cur);
            cur.clear();
        }

        int ret_value = 0;
        int item_value = 0;
        while (!calc_stack.empty()) {
            std::string item = calc_stack.top();
            calc_stack.pop();
            if (item == "+") {
                ret_value += item_value;
                item_value = 0;
            }
            else if (item == "-") {
                ret_value -= item_value;
                item_value = 0;
            }
            else {
                item_value = std::atoi(item.c_str());
            }
        }
        if (item_value != 0) {
            ret_value += item_value;
        }
        return ret_value;
    }
};