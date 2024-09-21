/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.
*/
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> s_vec = spilt(s);
        if (pattern.size() != s_vec.size()) {
            return false;
        }
        
        unordered_map<char, string> compare_map1;
        unordered_map<string, char> compare_map2;
        for (size_t i = 0; i < pattern.size(); i++) {
            auto iter1 = compare_map1.find(pattern[i]);
            if (iter1 == compare_map1.end()) {
                compare_map1[pattern[i]] = s_vec[i];

            } else {
                if (iter1->second != s_vec[i]) {
                    return false;
                }
            }

            auto iter2 = compare_map2.find(s_vec[i]);
            if (iter2 == compare_map2.end()) {
                compare_map2[s_vec[i]] = pattern[i];

            } else {
                if (iter2->second != pattern[i]) {
                    return false;
                }
            }
        }
        return true;
    }

    vector<string> spilt(string& s) {
        vector<string> ret;
        while (!s.empty()) {
            int index = s.find(' ');
            if (index == -1) {
                ret.emplace_back(s);
                break;
            }
            
            ret.emplace_back(s.substr(0, index));
            s = s.substr(index + 1, s.length() - index);
        }
        return ret;
    }
};