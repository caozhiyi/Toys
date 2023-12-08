#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> target_list;
        if (digits.empty()) {
            return target_list;
        }
        
        std::vector<std::string> list;
        list.reserve(digits.size());
        for (size_t i = 0; i < digits.size(); i++) {
            switch (digits[i])
            {
            case '2':
                list.emplace_back("abc");
                break;
            case '3':
                list.emplace_back("def");
                break;
            case '4':
                list.emplace_back("ghi");
                break;
            case '5':
                list.emplace_back("jkl");
                break;
            case '6':
                list.emplace_back("mno");
                break;
            case '7':
                list.emplace_back("pqrs");
                break;
            case '8':
                list.emplace_back("tuv");
                break;
            case '9':
                list.emplace_back("wxyz");
                break;
            default:
                break;
            }
        }
        pickOne(list, 0, "", target_list);
        return target_list;
    }

    void pickOne(std::vector<std::string>& list, int index, 
                 std::string target, std::vector<std::string>& target_list) {
        if (index >= list.size()) {
            target_list.push_back(target);
            return;
        }
        
        for (size_t i = 0; i < list[index].size(); i++) {
            pickOne(list, index+1, target + list[index][i], target_list);
        }
    }
};