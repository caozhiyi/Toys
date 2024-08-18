/*
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
*/
#include <vector>
#include <iostream>
class Solution {
public:
    static void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        if (m == 0 && n > 0) {
            for (int i = 0; i < n; ++i) {
                nums1[i] = nums2[i];
            }
            return;
        }
        // add data move to end side
        for (int end_index = nums1.size() - 1; end_index - n >= 0; end_index--) {
            nums1[end_index] = nums1[end_index - n];
        }

        int nums1_start = n;
        int nums2_start = 0;
        int cur_index = 0;
        while (cur_index < nums1.size()) {
            if (nums2_start < nums2.size() && nums1_start < nums1.size()) {
                if (nums2[nums2_start] < nums1[nums1_start]) {
                    nums1[cur_index] = nums2[nums2_start];
                    nums2_start++;

                } else {
                    nums1[cur_index] = nums1[nums1_start];
                    nums1_start++;
                }

            } else if (nums2_start < nums2.size()) {
                nums1[cur_index] = nums2[nums2_start];
                nums2_start++;

            } else {
                nums1[cur_index] = nums1[nums1_start];
                nums1_start++;
            }

            cur_index++;
        }
    }
};

/*
m,m,m,m,m,m,n,n,n,n
*/
