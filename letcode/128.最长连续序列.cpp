/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/
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