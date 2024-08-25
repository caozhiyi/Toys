/*
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
*/
#include <vector>
class Solution {
private:
    enum Direction {
        Right,
        Down,
        Left,
        Up,
    };

public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        int x = 0;
        int y = 0;

        int right_limit = matrix[0].size() - 1;
        int down_limit = matrix.size() - 1;
        int left_limit = 0;
        int up_limit = 1;
        int numx = matrix[0].size() * matrix.size();

        std::vector<int> ret;
        ret.reserve(numx);
        
        Direction direction = Right;
        do {
            ret.push_back(matrix[y][x]);
            numx--;
            switch (direction)
            {
            case Right:
                if (x < right_limit) {
                    x++; break;
                } else {
                    right_limit--;
                    direction = Down;
                }
            case Down:
                if (y < down_limit) {
                    y++; break;
                } else {
                    down_limit--;
                    direction = Left;
                }
            case Left:
                if (x > left_limit) {
                    x--;  break;
                } else {
                    left_limit++;
                    direction = Up;
                }
            case Up:
                if (y > up_limit) {
                    y--;  break;
                } else {
                    up_limit++;
                    direction = Right;

                    if (x < right_limit) {
                        x++; break;
                    }
                }
            }
        } while (numx > 0);
        return ret;
    }
};