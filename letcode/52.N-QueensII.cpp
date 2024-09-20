/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.
*/
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        vector<int> col(n, 0);
        unordered_set<int> col_used; 
        unordered_set<int> left_bottom_used;
        unordered_set<int> right_bottom_used;
        int out = 0;

        totalNQueens(n, 0, col, col_used, left_bottom_used, right_bottom_used, out);
        return out;
    }

    void totalNQueens(int n, int row, vector<int>& col,
        unordered_set<int>& col_used, unordered_set<int>& left_bottom_used,
        unordered_set<int>& right_bottom_used, int& out) {
        if (n == row) {
            out++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (col_used.count(i)) {
                continue;
            }
            
            int left_bottom = row - i;
            if (left_bottom_used.count(left_bottom)) {
                continue;
            }
            
            int right_bottom = row + i;
            if (right_bottom_used.count(right_bottom)) {
                continue;
            }
            
            col_used.insert(i);
            left_bottom_used.insert(left_bottom);
            right_bottom_used.insert(right_bottom);

            col[row] = i;
            totalNQueens(n, row + 1, col, col_used, left_bottom_used, right_bottom_used, out);

            col_used.erase(i);
            left_bottom_used.erase(left_bottom);
            right_bottom_used.erase(right_bottom);
        }
    }
};