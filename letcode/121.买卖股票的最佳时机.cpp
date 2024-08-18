/*
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
*/
#include <limits>
#include <vector>
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int max_profit = 0;
        for (size_t i = 0; i < prices.size(); i++) {
            for (size_t j = i+1; j < prices.size(); j++) {
                if (prices[i] < prices[j]) {
                    int cur_profit = prices[j] - prices[i];
                    if (cur_profit > max_profit) {
                        max_profit = cur_profit;
                    }
                }
            }
        }
        return max_profit;
    }

    int maxProfit1(std::vector<int>& prices) {
        if (prices.size() < 1) {
            return 0;
        }
        
        int max_profit = 0;
        int min_price = prices[0];
        for (size_t i = 1; i < prices.size(); i++) {
            if (min_price < prices[i]) {
                int cur_profit = prices[i] - min_price;
                if (cur_profit > max_profit) {
                    max_profit = cur_profit;
                }
               
            } else {
                 min_price = prices[i];
            }
        }
        return max_profit;
    }
};