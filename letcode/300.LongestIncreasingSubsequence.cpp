/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.
*/
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int max_subsequence = 1;
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    if (dp[i] > max_subsequence) {
                        max_subsequence = dp[i];
                    }
                }
            }
        }
        return max_subsequence;
    }
};

// dp index -> nums index, value -> longest subsequence
// index = max((nums[i] < nums[index]) + 1)