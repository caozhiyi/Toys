/*
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
*/
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int len = nums.size();
        for (size_t i = 0; i < len; i++) {
            nums.push_back(nums[i]);
        }
        
        int pre = 0;
        int maxRet = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            pre = max(pre + cur, cur);
            maxRet = max(maxRet, pre);
        }
        return maxRet;
    }
};

class Solution1 {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n);
        // 对坐标为 0 处的元素单独处理，避免考虑子数组为空的情况
        leftMax[0] = nums[0];
        int leftSum = nums[0];
        int pre = nums[0];
        int res = nums[0];
        for (int i = 1; i < n; i++) {
            pre = max(pre + nums[i], nums[i]);
            res = max(res, pre);
            leftSum += nums[i];
            leftMax[i] = max(leftMax[i - 1], leftSum);
        }

        // 从右到左枚举后缀，固定后缀，选择最大前缀
        int rightSum = 0;
        for (int i = n - 1; i > 0; i--) {
            rightSum += nums[i];
            res = max(res, rightSum + leftMax[i - 1]);
        }
        return res;
    }
};

class Solution2 {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        deque<pair<int, int>> q;
        int pre = nums[0], res = nums[0];
        q.push_back({0, pre});
        for (int i = 1; i < 2 * n; i++) {
            while (!q.empty() && q.front().first < i - n) {
                q.pop_front();
            }
            pre += nums[i % n];
            res = max(res, pre - q.front().second);
            while (!q.empty() && q.back().second >= pre) {
                q.pop_back();
            }
            q.push_back({i, pre});
        }
        return res;
    }
};