/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
*/
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) {
            return triangle[0][0];
        }
        vector<vector<int>> dp;
        dp.resize(triangle.size());

        for (int i = 0; i < triangle.size(); i++) {
            dp[i].resize(triangle[i].size());
        }
        
        dp[0][0] = triangle[0][0];

        int ret = numeric_limits<int>::max();
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[i][j] = numeric_limits<int>::max();
                if (j - 1 >= 0) {
                    dp[i][j] = min(dp[i][j], triangle[i - 1][j - 1] + triangle[i][j]);
                }
                if (j >= 0 && j < triangle[i - 1].size()) {
                    dp[i][j] = min(dp[i][j], triangle[i - 1][j] + triangle[i][j]);
                }
                if (i == triangle.size() - 1) {
                    ret = min(ret, dp[i][j]);
                }
            }
        }
        return ret;
    }
};

class Solution1 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) {
            return triangle[0][0];
        }

        int ret = numeric_limits<int>::max();
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int temp = numeric_limits<int>::max();
                if (j - 1 >= 0) {
                    temp = min(temp, triangle[i - 1][j - 1] + triangle[i][j]);
                }
                if (j >= 0 && j < triangle[i - 1].size()) {
                    temp = min(temp, triangle[i - 1][j] + triangle[i][j]);
                }
                triangle[i][j] = temp;

                if (i == triangle.size() - 1) {
                    ret = min(ret, triangle[i][j]);
                }
            }
        }
        return ret;
    }
};

// dp [x][y] x y-> index value ->min value
// dp [index] min(dp[index+1, index, index-1] + index)