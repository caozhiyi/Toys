/*
给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引用的次数。计算并返回该研究者的 h 指数。
根据维基百科上 h 指数的定义：h 代表“高引用次数” ，一名科研人员的 h 指数 是指他（她）至少发表了 h 篇论文，
并且 至少 有 h 篇论文被引用次数大于等于 h 。如果 h 有多种可能的值，h 指数 是其中最大的那个。
*/

#include <vector>
#include <algorithm>
class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        
        int max_h = 0;
        for (int may_h = citations.size(); may_h > 0; may_h--) {
            int cur_h = 0;
            for (int i = citations.size() - 1; i >= 0; i--) {
                if (citations[i] >= may_h && cur_h < may_h) {
                    cur_h++;

                } else {
                    break;
                }
            }
            if (max_h < cur_h) {
                max_h = cur_h;
            }
        }

        return max_h;
    }
};