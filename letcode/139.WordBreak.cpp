/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set<string>();
        for (auto word: wordDict) {
            wordDictSet.insert(word);
        }

        int last_index = 0;
        unordered_set<int> indexs;
        indexs.insert(0);

        for (int i = 1; i <= s.size(); ++i) {
            for (auto iter = indexs.begin(); iter != indexs.end(); iter++) {
                if (wordDictSet.count(s.substr(*iter, i - *iter))) {
                    indexs.insert(i);
                }
            }
        }

        return indexs.count(s.size());
    }
};

class Solution1 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set<string>();
        for (auto word: wordDict) {
            wordDictSet.insert(word);
        }

        int last_index = 0;
        for (int i = 1; i <= s.size(); ++i) {
            if (wordDictSet.count(s.substr(last_index, i - last_index))) {
                last_index = i;
            }
        }

        return last_index == s.size();
    }
};

// dp数组  
// 递推公式
// 初始化
// 遍历顺序