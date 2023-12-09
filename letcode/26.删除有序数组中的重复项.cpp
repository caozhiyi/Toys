#include <vector>
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int new_size = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[new_size] != nums[i]) {
                new_size++;
                if (new_size != i) {
                    nums[new_size] = nums[i];
                }
            }
        }
        return new_size+1;
    }
};