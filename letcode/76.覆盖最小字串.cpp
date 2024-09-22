/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
*/
#include <string>
#include <unordered_map>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        std::unordered_map<char, int> t_map;
        for (int i = 0; i < t.size(); i++) {
            t_map[t[i]]++;
        }
        
        int target_left = 0;
        int target_right = 100000;

        int left = 0;
        int right = 0;
        std::unordered_map<char, int> s_map;
        while (right < s.size()) {
            s_map[s[right]]++;

            while (check(s_map, t_map)) {
                if (target_right - target_left > right - left) {
                    target_left = left;
                    target_right = right;
                }
                auto iter = s_map.find(s[left]);
                iter->second--;
                if (iter->second == 0) {
                    s_map.erase(iter);
                }
                left++;
            }
            right++;
        }
        if (target_right == 100000) {
            return "";
        }
        
        return s.substr(target_left, target_right - target_left + 1);
    }

    bool check(std::unordered_map<char, int>& s_map, std::unordered_map<char, int>& t_map) {
        if (s_map.size() < t_map.size()) {
            return false;
        }
        
        for (auto iter = t_map.begin(); iter != t_map.end(); iter++) {
            auto s_iter = s_map.find(iter->first);
            if (s_iter == s_map.end()) {
                return false;
            }
            if (s_iter->second < iter->second) {
                return false;
            }
        }
        return true;
    }
};