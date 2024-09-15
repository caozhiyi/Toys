/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
*/
#include <vector>
#include <algorithm>
class Solution {
private:
    static bool compare(std::vector<int>& a, std::vector<int>& b) {
        return a[0] < b[0];
    }
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), Solution::compare);

        std::vector<std::vector<int>> ret;
        ret.reserve(intervals.size());
    
        int start = 0;
        int end = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (i == 0) {
                start = intervals[i][0];
                end = intervals[i][1];
                continue;
            }
            
            if (end < intervals[i][0]) {
                ret.push_back({start, end});

                start = intervals[i][0];
                end = intervals[i][1];
                
            } else {
                end = std::max(end,intervals[i][1]);
            }
        }
        // last group
        ret.push_back({start, end});
        return ret;
    }
};