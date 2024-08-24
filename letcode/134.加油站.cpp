
/*
在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。
*/

#include <vector>

class Solution {

public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int startIdx = 0; // 始发站
        int curGas = 0;   // 到达下一个加油站加油之前的累计剩余油量

        for (int i = 0; i < gas.size(); i++) {
            curGas += gas[i] - cost[i];
            if (curGas < 0) {
                // 走不动了, 说明之前的始发站不行，从i+1重新出发
                startIdx = i + 1;
                curGas = 0;
            }
        }
    
        // 判断累计剩余油量能否走完startIdx之前的加油站
        for (int i = 0; i < startIdx; i++) {
            curGas += gas[i] - cost[i];
            if (curGas < 0) {
                return -1;
            }
        }
        return startIdx;
    }
};