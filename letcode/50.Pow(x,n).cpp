/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
*/
#include <algorithm>
#include <limits>

class Solution {
public:
    double myPow(double x, int n) {
        if (abs(abs(x) - 1) < 0.00000001) {
            if (n%2) {
                return x;
            }
            return abs(x);
        }
        
        if (n > 0) {
            double ret = x;
            for (int i = 1; i < n; i++) {
                ret *= x;
            }
            return ret;

        } else if (n < 0) {
            if (n <= std::numeric_limits<int>::min() + 100) {
                return 0;
            }
            
            double ret = 1;
            for (int i = 0; i < -n; i++) {
                ret = ret / x;
            }
            return ret;

        } else {
            return 1;
        }
    }
};