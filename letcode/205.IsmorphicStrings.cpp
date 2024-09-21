/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        unordered_map<char, char> compare_map1;
        unordered_map<char, char> compare_map2;
        for (size_t i = 0; i < s.size(); i++) {
            auto iter1 = compare_map1.find(s[i]);
            if (iter1 == compare_map1.end()) {
                compare_map1[s[i]] = t[i];

            } else {
                if (iter1->second != t[i]) {
                    return false;
                }
            }

            auto iter2 = compare_map2.find(t[i]);
            if (iter2 == compare_map2.end()) {
                compare_map2[t[i]] = s[i];

            } else {
                if (iter2->second != s[i]) {
                    return false;
                }
            }

        }
        return true;
    }
};