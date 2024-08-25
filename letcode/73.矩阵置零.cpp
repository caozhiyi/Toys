/*
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
*/
#include <vector>
class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        std::vector<std::pair<int, int>> zero_indexs;
        for (int y = 0; y < matrix.size(); y++) {
            for (int x = 0; x < matrix[0].size(); x++) {
                if (matrix[y][x] == 0) {
                    zero_indexs.push_back({y, x});
                }
            }
        }
        
        for (int i = 0; i < zero_indexs.size(); i++) {
            zero(matrix, zero_indexs[i].first,  zero_indexs[i].second);
        }
    }

    void zero(std::vector<std::vector<int>>& matrix, int y, int x) {
        for (int i = x - 1; i >= 0; i--) {
            matrix[y][i] = 0;
        }
        
        for (int i = x + 1; i < matrix[0].size(); i++) {
            matrix[y][i] = 0;
        }
        
        for (int i = y + 1; i < matrix.size(); i++) {
            matrix[i][x] = 0;
        }
        
        for (int i = y - 1; i >= 0; i--) {
            matrix[i][x] = 0;
        }
    }
};