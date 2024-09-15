/*
给你一个 无重叠的 ，按照区间起始端点排序的区间列表 intervals，其中 intervals[i] = [starti, endi] 表示第 i 个区间的开始和结束，并且 intervals 按照 starti 升序排列。
同样给定一个区间 newInterval = [start, end] 表示另一个区间的开始和结束。
在 intervals 中插入区间 newInterval，使得 intervals 依然按照 starti 升序排列，且区间之间不重叠（如果有必要的话，可以合并区间）。
返回插入之后的 intervals。
注意 你不需要原地修改 intervals。你可以创建一个新数组然后返回它
*/
#include <vector>
#include <algorithm>
class Solution {
    static bool compare(std::vector<int>& a, std::vector<int>& b) {
        return a[0] < b[0];
    }
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        intervals.push_back(newInterval);
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