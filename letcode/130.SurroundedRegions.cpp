/*
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells 
and none of the region cells are on the edge of the board.
A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.
*/
#include <vector>
class Solution {
public:
    void solve(std::vector<std::vector<char>>& board) {
        for (int x = 0; x < board.size(); x++) {
            dfs(board, x, 0);
            dfs(board, x, board[0].size() - 1);
        }

        for (int y = 0; y < board[0].size(); y++) {
            dfs(board, 0, y);
            dfs(board, board.size() - 1, y);
        }

        for (int x = 0; x < board.size(); x++) {
            for (int y = 0; y < board[0].size(); y++) {
                if (board[x][y] == 'O') {
                    board[x][y] = 'X';
                }
                if (board[x][y] == 'A') {
                    board[x][y] = 'O';
                }
            }
        }
    }

    void dfs(std::vector<std::vector<char>>& board, int x, int y) {
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != 'O') {
            return;
        }

        board[x][y] = 'A';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }
};