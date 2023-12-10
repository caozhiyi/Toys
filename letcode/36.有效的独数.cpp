#include <vector>

class Solution {
private:
    enum NumBit {
        One   = 1,
        Two   = 1 << 1,
        Three = 1 << 2,
        Four  = 1 << 3,
        Five  = 1 << 4,
        Six   = 1 << 5,
        Seven = 1 << 6,
        Eight = 1 << 7,
        Nine  = 1 << 8,
        All   = One|Two|Three|Four|Five|Six|Seven|Eight|Nine,
    };
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        for (size_t i = 0; i < board.size(); i++) {
            int num_bit_1 = 0;
            int num_bit_2 = 0;
            
            for (size_t j = 0; j < board[i].size(); j++) {
                // 横向检查
                if (!calcBit(board[j][i], num_bit_1)) {
                    return false;
                }
                // 纵向检查
                if (!calcBit(board[i][j], num_bit_2)) {
                    return false;
                }

                if (i % 3 != 0 || j % 3 != 0) {
                    continue;
                }

                // 3*3 检查
                int num_bit_3 = 0;
                for (size_t x = i; x < i + 3; x++) {
                    for (size_t y = j; y < j + 3; y++) {
                        if (!calcBit(board[x][y], num_bit_3)) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    bool calcBit(char value, int& num_bit) {
        switch (value) {
        case '1':
            if (num_bit & One) {
                return false;
            }
            num_bit |= One;
            break;
        case '2':
            if (num_bit & Two) {
                return false;
            }
            num_bit |= Two;
            break;
        case '3':
            if (num_bit & Three) {
                return false;
            }
            num_bit |= Three;
            break;
        case '4':
            if (num_bit & Four) {
                return false;
            }
            num_bit |= Four;
            break;
        case '5':
            if (num_bit & Five) {
                return false;
            }
            num_bit |= Five;
            break;
        case '6':
            if (num_bit & Six) {
                return false;
            }
            num_bit |= Six;
            break;
        case '7':
            if (num_bit & Seven) {
                return false;
            }
            num_bit |= Seven;
            break;
        case '8':
            if (num_bit & Eight) {
                return false;
            }
            num_bit |= Eight;
            break;
        case '9':
            if (num_bit & Nine) {
                return false;
            }
            num_bit |= Nine;
            break;
        default:
            break;
        }
        return true;
    }
};