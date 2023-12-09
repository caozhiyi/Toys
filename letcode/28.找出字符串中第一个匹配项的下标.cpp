#include <string>
class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int ret = -1;
        if (haystack.empty() || needle.empty()) {
            return ret;
        }

        for (size_t i = 0; i < haystack.length(); i++) {
            if (haystack[i] == needle[0]) {
                bool match = true;
                for (size_t j = 0; j < needle.length(); j++) {
                    if (haystack[i + j] != needle[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    ret = i;
                    break;
                }
            }
        }
        return ret;
    }
};