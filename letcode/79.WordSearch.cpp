/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
*/
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) {
            return false;
        }
        
        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] != word[0]) {
                    continue;
                }
                
                used[row][col] = true;

                if (exist(row, col, used, board, 1, word)) {
                    return true;
                }
            
                used[row][col] = false;
            }
        }
        
        return false;
    }


    bool exist(int row, int col, vector<vector<bool>>& used,
        const vector<vector<char>>& board,
        int cur_index, const string& word) {
        if (cur_index >= word.size()) {
            return true;
        }
        
        if (row + 1 < board.size() && !used[row + 1][col] && board[row + 1][col] == word[cur_index]) {
            used[row + 1][col] = true;
            if (exist(row + 1, col, used, board, cur_index + 1, word)) {
                return true;
            }
            used[row + 1][col] = false;
        }
        
        if ( row - 1 >= 0 && !used[row - 1][col] && board[row - 1][col] == word[cur_index]) {
            used[row - 1][col] = true;
            if (exist(row - 1, col, used, board, cur_index + 1, word)) {
                return true;
            }
            used[row - 1][col] = false;
        }

        if (col + 1 < board[0].size() && !used[row][col + 1] && board[row][col + 1] == word[cur_index]) {
            used[row][col + 1] = true;
            if (exist(row, col + 1, used, board, cur_index + 1, word)) {
                return true;
            }
            used[row][col + 1] = false;
        }
        
        if (col - 1 >= 0 && !used[row][col - 1] && board[row][col - 1] == word[cur_index]) {
            used[row][col - 1] = true;
            if (exist(row, col - 1, used, board, cur_index + 1, word)) {
                return true;
            }
            used[row][col - 1] = false;
        }
        return false;
     }
};

class Solution1 {
public:
    bool search(vector<vector<char>>& board, string word, int wordIndex, int i, int j, vector<vector<bool>>& visited) {
        if (wordIndex == word.size()) return true;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        int m = board.size();
        int n = board[0].size();

        for (int k = 0; k < 4; k++) {
            int newI = i + dx[k];
            int newJ = j + dy[k];

            if (newI >= 0 && newI < m && newJ >= 0 && newJ < n &&!visited[newI][newJ] && board[newI][newJ] == word[wordIndex]) {
                visited[newI][newJ] = true;
                if (search(board, word, wordIndex + 1, newI, newJ, visited)) return true;
                visited[newI][newJ] = false;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (search(board, word, 1, i, j, visited)) return true;
                    visited[i][j] = false;
                }
            }
        }

        return false;
    }
};