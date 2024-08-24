/*
给你一个字符串 s ，请你反转字符串中 单词 的顺序。
单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
*/
#include <string>
class Solution {
public:
    std::string reverseWords(std::string s) {
        if (s.empty()) {
            return s;
        }
        
        std::string ret;
        ret.resize(s.length());

        int start = -1;
        int end = -1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                if (end == -1) {
                    end = i;
                    start = i;

                } else {
                    start = i;
                }

            } else {
                if (start != -1 && end != -1) {
                    ret.append(s.substr(start, end - start));
                    ret.append(" ");
                    start = -1;
                    end = -1;
                }
            }
        }
        return ret;
    }
};