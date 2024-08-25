/*
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
*/
#include <string>
class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        if (s.empty()) {
            return true;
        }
        
        int t_index = 0;
        bool find;
        for (int i = 0; i < s.size(); i++) {
            find = false;
            for (; t_index < t.size(); t_index++) {
                if (s[i] == t[t_index]) {
                    t_index++;
                    find = true;
                    break;
                }
            }
        }
        return find;
    }
};