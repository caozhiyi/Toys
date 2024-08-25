/*
如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。
字母和数字都属于字母数字字符。
给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。
*/
#include <string>
class Solution {
public:
    bool isPalindrome(std::string s) {
        removeOther(s);

        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void removeOther(std::string& s) {
        int start = -1;
        int other_times = 0;
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= '0' && s[i] <= '9')) {

                if ((s[i] >= 'A' && s[i] <= 'Z')) {
                    s[i] = s[i] - 26;
                }
                
                if (start != i) {
                    s[start] = s[i];
                    start++;
                }

            } else {
                if (start != -1) {
                    start = i;
                }
                other_times++;
            }
        }
        s.resize(s.size() - other_times);
    }
};

class Solution2 {
public:
    bool isPalindrome(std::string s) {

        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (!isValid(s[left])) {
                left++;
                continue;
            }
            
            if (!isValid(s[right])) {
                right--;
                continue;
            }
            
            if (!isEqual(s[left], s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    bool isValid(char s) {
        return ((s >= 'A' && s <= 'Z') ||
                (s >= 'a' && s <= 'z') ||
                (s >= '0' && s <= '9'));
    }

    bool isEqual(char a, char b) {
        return std::tolower(a) == std::tolower(b);
    }
};