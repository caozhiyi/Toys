#include <vector>
#include <algorithm>
#include <unordered_map>
class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_map<int,int> m;
        int result = 0;
        for(int n : nums ) {
            if( m.find(n) != m.end() ) continue;
            int left = m.find(n-1) == m.end() ? 0 : m[n-1];
            int right = m.find(n+1) == m.end() ? 0 : m[n+1];
            int len = left + right + 1;
            m[n] = 1;
            m[n-left] = m[n+right] = len;
            result = std::max(result, len);
        }
        return result;
    }
};