/*
Write a function that takes the binary representation of a positive integer and returns the number of 
set bits
 it has (also known as the Hamming weight).
*/

class Solution {
public:
    int hammingWeight(int n) {
        int ret = 0;
        while (n) {
            if (n & 1) {
                ret++;
            }
            n = n >> 1;
        }
        return ret;
    }
};