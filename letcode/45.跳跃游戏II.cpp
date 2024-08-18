/*
给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
*/
#include <vector>
class Solution {
public:
    int jump(std::vector<int>& nums) {
        int jump_times = 0;
        for (int i = nums.size() - 1; i > 0;) {
            int max_distance = 1;
            for (int j = i - 1; j >= 0; j--) {
                int cur_distance = i - j;
                if (cur_distance <= nums[j]) {
                    if (cur_distance > max_distance) {
                        max_distance = cur_distance;
                    }
                }
            }
            jump_times++;
            i = i - max_distance;
        }
        return jump_times;
    }
};