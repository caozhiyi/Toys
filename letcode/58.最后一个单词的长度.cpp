/*
给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。
单词 是指仅由字母组成、不包含任何空格字符的最大子字符串
*/
#include <string>
class Solution {
public:
    int lengthOfLastWord(std::string s) {
        if (s.empty()) {
            return 0;
        }
        
        bool start = false;
        int length = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (!start && s[i] == ' ') {
                continue;
            }
            start = true;

            if (s[i] != ' ') {
                length++;

            } else {
                break;
            }
        }
        return length;
    }
};