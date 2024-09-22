/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        for (int i = 0; i < obstacleGrid.size(); i++) {
            for (int j = 0; j < obstacleGrid[i].size(); j++) {
                if (i == 0 && j == 0 && obstacleGrid[i][j] != 1) {
                    obstacleGrid[i][j] = 1;
                    continue;
                }
                
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = 0;
                    continue;
                }
                
                int temp = 0;
                if (i - 1 >= 0 && obstacleGrid[i - 1][j] > 0) {
                    temp += obstacleGrid[i - 1][j];
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] > 0) {
                    temp += obstacleGrid[i][j - 1];
                }
                obstacleGrid[i][j] = temp;
            }
        }
        return obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};