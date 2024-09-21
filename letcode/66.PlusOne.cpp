/*
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.
*/
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool up = false;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (i == digits.size() - 1) {
                if (digits[i] == 9) {
                    digits[i] = 0;
                    up = true;
                    continue;
                }

                digits[i] = digits[i] + 1;
                break;
            }
            
            if (up) {
                if (digits[i] == 9) {
                    digits[i] = 0;
                    continue;
                }

                digits[i] = digits[i] + 1;
                up = false;
                break;
            }
        }

        if (up) {
            vector<int> ret;
            ret.reserve(digits.size() + 1);
            ret.push_back(1);
            for (size_t i = 0; i < digits.size(); i++) {
                ret.push_back(digits[i]);
            }
            return ret;
        }
        
        return digits;
    }
};