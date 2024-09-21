/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int len = rows * cols;

        int left = 0;
        int right = len - 1;
        while (left <= right) {
            auto cur_index = (left + right) / 2;
            auto index = parseIndex(cols, cur_index);
            if (matrix[index.first][index.second] < target) {
                left = cur_index + 1;

            } else if (matrix[index.first][index.second] > target) {
                right = (left + right) / 2 - 1;

            } else {
                return true;
            }
        }
        return false;
    }

    pair<int, int> parseIndex(int cols, int index) {
        int row = index / cols;
        int col = index % cols;
        return {row, col};
    } 
};