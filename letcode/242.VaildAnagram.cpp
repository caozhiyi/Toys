/*
Given two strings s and t, return true if t is an 
anagram of s, and false otherwise.
*/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        unordered_map<char, int> s_map;
        for (size_t i = 0; i < s.size(); i++) {
            s_map[s[i]]++;
        }
        
        for (size_t i = 0; i < t.size(); i++) {
            auto iter = s_map.find(t[i]);
            if (iter == s_map.end()) {
                return false;
            }
            
            iter->second--;
            if (iter->second <= 0) {
                s_map.erase(iter);
            }
        }
        
        return s_map.empty();
    }
};