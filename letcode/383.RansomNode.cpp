/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.
*/
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magazine_map;
        for (int i = 0; i < magazine.size(); i++) {
            magazine_map[magazine[i]]++;
        }
        
        for (int i = 0; i < ransomNote.size(); i++) {
            auto iter = magazine_map.find(ransomNote[i]);
            if (iter != magazine_map.end()) {
                iter->second--;

                if (iter->second <= 0) {
                    magazine_map.erase(iter);
                }
                
            } else {
                return false;
            }
        }

        return true;
    }
};

class Solution1 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        vector<int> cnt(26);
        for (auto & c : magazine) {
            cnt[c - 'a']++;
        }
        for (auto & c : ransomNote) {
            cnt[c - 'a']--;
            if (cnt[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};