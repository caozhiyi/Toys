/*
根据 百度百科 ， 生命游戏 ，简称为 生命 ，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。
给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。
每个细胞都具有一个初始状态： 1 即为 活细胞 （live），或 0 即为 死细胞 （dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。给你 m x n 网格面板 board 的当前状态，返回下一个状态。
*/
#include <vector>
class Solution {
public:
    void gameOfLife(std::vector<std::vector<int>>& board) {
        std::vector<std::pair<int, int>> change_indexs;
        for (int y = 0; y < board.size(); y++) {
            for (int x = 0; x < board[0].size(); x++) {
                if (checkChange(board, x, y)) {
                    change_indexs.push_back({x, y});
                }
            }
        }
        
        for (int i = 0; i < change_indexs.size(); i++) {
            board[change_indexs[i].second][change_indexs[i].first] = board[change_indexs[i].second][change_indexs[i].first] == 1 ? 0: 1;
        }
    }

    bool checkChange(std::vector<std::vector<int>>& board, int x, int y) {
        int live_count = 0;
        if (x + 1 < board[0].size()) {
            live_count += board[y][x + 1] == 1 ? 1 : 0;
        }
        if (x - 1 >= 0) {
            live_count += board[y][x - 1] == 1 ? 1 : 0;
        }
        if (y - 1 >= 0) {
            live_count += board[y - 1][x] == 1 ? 1 : 0;
        }
        if (y + 1 < board.size()) {
            live_count += board[y + 1][x] == 1 ? 1 : 0;
        }
        if (x + 1 < board[0].size() && y - 1 >= 0) {
            live_count += board[y - 1][x + 1] == 1 ? 1 : 0;
        }
        if (x + 1 < board[0].size() && y + 1 < board.size()) {
            live_count += board[y + 1][x + 1] == 1 ? 1 : 0;
        }
        if (x - 1 < board[0].size() && y + 1 < board.size()) {
            live_count += board[y + 1][x - 1] == 1 ? 1 : 0;
        }
        if (x - 1 < board[0].size() && y - 1 >= 0) {
            live_count += board[y - 1][x - 1] == 1 ? 1 : 0;
        }

        bool is_live = board[y][x] == 1;
        if (is_live) {
            if (live_count < 2) {
                return true;
            }
            if (live_count > 3) {
                return true;
            }
        } else {
            if (live_count == 3) {
                return true;
            }
        }
        return false;
    }
};