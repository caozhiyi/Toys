#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> ret;
        if (strs.empty()) {
            return ret;
        }
        
        std::unordered_map<std::string, std::vector<std::string>> ret_map;
        for (size_t i = 0; i < strs.size(); i++) {
            ret_map[sortString(strs[i])].emplace_back(strs[i]);
        }
        
        ret.reserve(ret_map.size());
        for (auto iter = ret_map.begin(); iter != ret_map.end(); iter++) {
            ret.emplace_back(std::move(iter->second));
        }
        return ret;
    }

    std::string sortString(std::string str) {
        std::sort(str.begin(), str.end());
        return str;
    }
};