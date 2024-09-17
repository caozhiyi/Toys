/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.
*/
#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int ret = 0;
        for (int x = 0; x < grid.size(); x++) {
            for (int y = 0; y < grid[0].size(); y++) {
                if (grid[x][y] == 'x') {
                    continue;
                }
                if (grid[x][y] == '1') {
                    trans(grid, x, y);
                    ret++;
                }
            }
        }
        return ret;
    }

    void trans(std::vector<std::vector<char>>& grid, int x, int y) {
        int cur_x = x;
        int cur_y = y + 1;
        if (cur_y < grid[0].size() && cur_y >= 0) {
            if (grid[cur_x][cur_y] == '1') {
                grid[cur_x][cur_y] = 'x';
                trans(grid, cur_x, cur_y);
            }
        }

        cur_x = x;
        cur_y = y - 1;
        if (cur_y < grid[0].size() && cur_y >= 0) {
            if (grid[cur_x][cur_y] == '1') {
                grid[cur_x][cur_y] = 'x';
                trans(grid, cur_x, cur_y);
            }
        }
        
        cur_x = x + 1;
        cur_y = y;
        if (cur_x < grid.size() && cur_x >= 0) {
            if (grid[cur_x][cur_y] == '1') {
                grid[cur_x][cur_y] = 'x';
                trans(grid, cur_x, cur_y);
            }
        }
        
        cur_x = x - 1;
        cur_y = y;
        if (cur_x < grid.size() && cur_x >= 0) {
            if (grid[cur_x][cur_y] == '1') {
                grid[cur_x][cur_y] = 'x';
                trans(grid, cur_x, cur_y);
            }
        }
    }
};