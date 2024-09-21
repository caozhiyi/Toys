/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
*/
#include <cstdint>
#include <limits>

class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;
        int ret = 0;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid) {
                ret = mid;
                left = mid + 1;

            } else {
                right = mid - 1;
            }
        }
        return ret;
    }
};

class Solution1 {
public:
    int mySqrt(int x) {
        int i = 1;
        int j = x;
        int ans = 0;
        while (i <= j){
            int mid = i + (j-i)/2;
            // upper bound的形式，因为我们要找的ans要是最接近于x的最大的数，利用upper bound
            if (mid <= x/mid){
                i = mid +1;
                ans = mid; // 只要mid <= x/mid，left左边界就会一直向右移动，ans就会一直更新（变大），直到不在满足mid <= x/mid的条件为止，ans就会停止更新，永远停在满足mid<=x/mid条件下面的最后一次更新，即满足ans * ans <= mid的最大值。
            }
            else
                j = mid-1;
        }
        
        return ans;
    }
};