/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
*/
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0;
        int maxRet = nums[0];
        
        for (const auto &i : nums) {
            pre = max(pre + i, i);
            maxRet = max(maxRet, pre);
        }
        return maxRet;
    }
};

class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxAns=nums[0];
        for(int x:nums){
            sum+=x;
            if(sum>maxAns) maxAns=sum;
            if(sum<0) sum=0;
        }
        return maxAns;
    }
};