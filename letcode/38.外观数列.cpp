#include <string>
class Solution {
public:
    std::string countAndSay(int n) {
        std::string ret = "1";
        for (size_t i = 1; i < n; i++) {
            ret = next(ret);
        }
        return ret;
    }

    std::string next(std::string& str) {
        std::string ret;
        char last_char;
        int last_char_count = 1;
        for (int i = str.length() - 1; i >= 0; i--) {
            if (i == str.length() - 1) {
                last_char = str[i];
                continue;
            }
            
            if (last_char == str[i]) {
                last_char_count++;

            } else {
                ret = std::to_string(last_char_count) + last_char + ret;
                
                last_char = str[i];
                last_char_count = 1;
            }
        }
        ret = std::to_string(last_char_count) + last_char + ret;
        return ret;
    }
};