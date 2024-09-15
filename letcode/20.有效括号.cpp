/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
*/
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        if (s.size() % 2 != 0) {
            return false;
        }
        
        std::stack<char> char_stack;
        for (size_t i = 0; i < s.size(); i++) {
            switch (s[i]) {
            case '(':
            case '[':
            case '{':
                char_stack.push(s[i]);
                break;

            case ')':
            case ']':
            case '}':
                if (char_stack.empty()) {
                    return false;
                }

                if (char_stack.top() == getChar(s[i])) {
                    char_stack.pop();

                } else {
                    return false;
                }
                break;

            default:
                break;
            }
        }
        return char_stack.empty();
    }

    char getChar(char c) {
        switch (c)
        {
        case ')':
            return '(';
        case '}':
            return '{';
        case ']':
            return '[';
        default:
            return c;
        }
    }
};