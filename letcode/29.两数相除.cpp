#include <limits>
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == std::numeric_limits<int>::max()) {
            if (divisor == 1) {
                return dividend;
            }
            
            if (divisor == -1) {
                return dividend == std::numeric_limits<int>::min();
            }
        }

        if (divisor == std::numeric_limits<int>::min()) {
            return dividend == std::numeric_limits<int>::min() ? 1 : 0;
        }
        
        if (divisor == 0) {
            return 0;
        }
        

    }
};