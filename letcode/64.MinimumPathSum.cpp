/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 1 && grid[0].size() == 1) {
            return grid[0][0]; 
        }
        
        int target_i = grid.size() - 1;
        int target_j = grid[0].size() - 1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                // from up
                int temp = numeric_limits<int>::max();
                if (i - 1 >= 0) {
                    temp = min(temp, grid[i - 1][j] + grid[i][j]);
                }
                if (j - 1 >= 0) {
                    temp = min(temp, grid[i][j - 1] + grid[i][j]);
                }
                
                grid[i][j] = temp;
                if (i == target_i && j == target_j) {
                    return temp;
                }
            }
        }
        return 0;
    }
};