#include <vector>
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }

        int first = 1;
        int second = 2;
        int target = 0;
        for (size_t i = 2; i < n; i++) {
            target = second + first;
            first = second;
            second = target;
        }
        return target;
    }
};