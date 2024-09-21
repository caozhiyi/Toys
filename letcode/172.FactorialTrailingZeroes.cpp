/*
Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 1;
        for (int i = 1; i <= n; i++) {
            ret *= i;
        }

        int count = 0;
        while (ret > 0 && ret % 10 == 0) {
            count++;
            ret = ret / 10;
        }
        return count;
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int times = 1;
        for (int i = 5; i <= n; i += 5) {
            for (int x = i; x % 5 == 0; x /= 5) {
                ++ans;
            }
        }
        return ans;
    }
};