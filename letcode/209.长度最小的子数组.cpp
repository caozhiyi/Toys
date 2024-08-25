/*
给定一个含有 n 个正整数的数组和一个正整数 target
找出该数组中满足其总和大于等于 target 的长度最小的 子数组
[numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
*/
#include <vector>
#include <algorithm>
class Solution {
public:
    int minSubArrayLen(int s, std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = nums.size() + 1;
        int start = 0, end = 0;
        int sum = 0;
        while (end < n) {
            sum += nums[end];
            while (sum >= s) {
                ans = std::min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return ans > nums.size() ? 0 : ans;
    }
};