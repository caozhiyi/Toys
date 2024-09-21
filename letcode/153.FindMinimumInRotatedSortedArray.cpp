/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.
*/
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size() - 1);
    }

    int binarySearch(vector<int>& nums, int start, int end) {
        if (nums[start] > nums[end]) {
            while (start < end) {
                int mid = (start + end) / 2;
                if (nums[mid] >= nums[0]) {
                    start = mid + 1;

                } else {
                    if (nums[mid] > (nums[mid - 1])) {
                        end = mid - 1;

                    } else {
                        return nums[mid];
                    }
                }
            }
            return nums[end];

        } else {
            return nums[start];
        }
    }
};

class Solution1 {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;

            } else {
                left = left + 1;
            }
        }
        return nums[left];
    }
};