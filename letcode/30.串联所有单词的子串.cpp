#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> ret;
        if (words.empty()) {
            return ret;
        }
        
        std::unordered_map<std::string, int> words_map;
        int step = words[0].size();
        int total_words_count = 0;
        for (size_t i = 0; i < words.size(); i++) {
            words_map[words[i]]++;
            total_words_count += step;
        }
        
        int index = 0;
        while (index <= (int)s.length() - total_words_count) {
            char* begin = (char*)s.c_str() + index;
            std::string temp(begin, step);
            if (words_map.find(temp) != words_map.end()) {

                bool match = true;
                int count = 0;
                std::unordered_map<std::string, int> temp_map = words_map;

                while (count < words.size()) {
                    std::string temp2(begin, step);
                    auto iter = temp_map.find(temp2);
                    if (iter != temp_map.end()) {
                        iter->second--;
                        if (iter->second <= 0) {
                            temp_map.erase(iter);
                        }
                        begin += step;

                    } else {
                        match = false;
                        break;
                    }
                    count++;
                }

                if (match && temp_map.empty()) {
                    ret.push_back(index);
                }
            }
            index++;
        }
        return ret;
    }
};