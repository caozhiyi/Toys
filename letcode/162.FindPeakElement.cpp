/*
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.
*/
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        
        if (nums.size() == 2) {
            return nums[0] < nums[1] ? 1 : 0;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                if (nums[i] > nums[i+1]) {
                    return i;
                }
                continue;
            }
            if (i == nums.size() - 1) {
                if (nums[i] > nums[i-1]) {
                    return i;
                }
                continue;
            }
            
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;

        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            //mid-1 到 mid的趋势，上升为+，下降为-
            int pre = mid == 0 ? 1 : nums[mid] - nums[mid - 1];
            int next = mid == nums.size() - 1 ? -1 : nums[mid + 1] - nums[mid];
            //峰值
            if(pre > 0 && next < 0)
                return mid;
            //向右是上升趋势，则右边一定右峰值
            if (next > 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};