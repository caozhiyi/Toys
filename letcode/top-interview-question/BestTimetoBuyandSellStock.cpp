/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.
*/
#include <vector>
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() <=1){
            return 0;
        }
        int a = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i]>prices[i-1]){
                a+= (prices[i]-prices[i-1]);
            }
        }
        return a;
    }
};