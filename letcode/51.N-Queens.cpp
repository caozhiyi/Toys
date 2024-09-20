/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> col;
        col.resize(n);

        unordered_set<int> col_used;
        unordered_set<int> left_bottom_used;
        unordered_set<int> right_bottom_used;
        vector<vector<string>> output;

        solveNQueens(0, n, col, col_used, left_bottom_used, right_bottom_used, output);

        return output;
    }

    void solveNQueens(int row, int n, vector<int>& col, 
        unordered_set<int>& col_used, unordered_set<int>& left_bottom_used,
        unordered_set<int>& right_bottom_used, vector<vector<string>>& output) {

        if (row == n) {
            output.emplace_back(generateResult(n, col));
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (col_used.count(i) > 0) {
                continue;
            }
            
            int left_bottom = row - i;
            if (left_bottom_used.count(left_bottom) > 0) {
                continue;
            }
            
            int right_bottom = row + i;
            if (right_bottom_used.count(right_bottom) > 0) {
                continue;
            }

            col_used.insert(i);
            left_bottom_used.insert(left_bottom);
            right_bottom_used.insert(right_bottom);

            col[row] = i;
            solveNQueens(row + 1, n, col, col_used, left_bottom_used, right_bottom_used, output);

            col_used.erase(i);
            left_bottom_used.erase(left_bottom);
            right_bottom_used.erase(right_bottom);
        }
    }

    std::vector<string> generateResult(int n, const std::vector<int>& col) {
        std::vector<string> ret;
        ret.resize(n);
        for (int i = 0; i < n; i++) {
            string temp(n, '.');
            temp[col[i]] = 'Q';
            ret[i] = temp;
        }
        return ret;
    }
};