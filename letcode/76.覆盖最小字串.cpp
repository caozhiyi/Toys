/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
*/
#include <string>
#include <unordered_map>
class Snapshot {
public:
    Snapshot() {}
    Snapshot(const std::string& s) {
        for (size_t i = 0; i < s.size(); i++) {
            _map[s[i]]++;
        }
    }

    void add(char s) {
        _map[s]++;
    }

    void remove(char s) {
        auto iter = _map.find(s);
        if (iter != _map.end()) {
            iter->second--;
            if (iter->second <= 0) {
                _map.erase(iter);
            }
        }
    }

    bool contine(char s) {
        return _map.count(s) > 0;
    }

    bool contine(Snapshot& s) {
        if (_map.size() < s._map.size()) {
            return false;
        }

        for (auto iter = s._map.begin(); iter != s._map.end(); iter++) {
            auto find_iter = _map.find(iter->first);
            if (find_iter != _map.end() && find_iter->second >= iter->second) {
                continue;
            }
            return false;
        }
        return true;
    }

private:
    std::unordered_map<char, int> _map; // char -> times
};

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        Snapshot target_snoapshot(t);

        int min_start = -1;
        int min_end = s.size() + 1;
        int start = 0;
        int end = 0;
        Snapshot cur_snoapshot;
        std::string ret;
        while (end < s.size()) {
            cur_snoapshot.add(s[end]);
            while (cur_snoapshot.contine(target_snoapshot)) {
                if (min_end - min_start > end - start) {
                    min_start = start;
                    min_end = end;
                    ret = s.substr(start, end - start + 1);
                }
                cur_snoapshot.remove(s[start]);
                start++;
            }
            end++;
        }
        if (min_start == -1) {
            return "";
        }
        return ret;
    }
};