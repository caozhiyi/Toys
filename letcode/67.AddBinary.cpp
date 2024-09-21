/*
Given two binary strings a and b, return their sum as a binary string.
*/
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ret = a.size() > b.size() ? a : b;
        bool up = false;
        for (int ai = a.size() - 1, bi = b.size() - 1; ai >= 0 || bi >= 0; ai--, bi--) {
            if (ai >= 0 && bi >= 0) {
                int cur = ai > bi ? ai : bi;
                if (a[ai] == '1' && b[bi] == '1') {
                    ret[cur] = up ? '1' : '0';
                    up = true;
                    continue;
                }
                
                if (b[bi] == '1' || a[ai] == '1') {
                    ret[cur] = up ? '0' : '1';
                    continue;
                }
                
                if (up) {
                    ret[cur] = '1';
                    up = false;
                }
                continue;
            }
            
            if (ai >= 0) {
                if (a[ai] == '1') {
                    ret[ai] = up ? '0' : '1';
                    continue;
                }

                if (up) {
                    ret[ai] = '1';
                    up = false;
                }
                break;
            }

            if (bi >= 0) {
                if (b[bi] == '1') {
                    ret[bi] = up ? '0' : '1';
                    continue;
                }

                if (up) {
                    ret[bi] = '1';
                    up = false;
                }
                break;
            }
        }
        
        return up ? '1' + ret : ret;
    }
};