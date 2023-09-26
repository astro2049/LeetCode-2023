#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<bool>> rows, cols;
    vector<vector<vector<bool>>> boxes;
    vector<vector<int>> blanks;

    void solveSudoku(vector<vector<char>> &board) {
        rows.resize(9, vector<bool>(9)), cols.resize(9, vector<bool>(9));
        boxes.resize(3, vector<vector<bool>>(3, vector<bool>(9)));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    int num = board[i][j] - '1';
                    rows[i][num] = true;
                    cols[j][num] = true;
                    boxes[i / 3][j / 3][num] = true;
                } else {
                    blanks.push_back({i, j});
                }
            }
        }
        dfs(board, 0);
    }

    bool dfs(vector<vector<char>> &board, int n) {
        if (n == blanks.size()) {
            return true;
        }
        auto ij = blanks[n];
        int i = ij[0], j = ij[1];
        for (int k = 0; k < 9; k++) {
            if (!rows[i][k] && !cols[j][k] && !boxes[i / 3][j / 3][k]) {
                rows[i][k] = true, cols[j][k] = true, boxes[i / 3][j / 3][k] = true;
                board[i][j] = k + '1';
                if (dfs(board, n + 1)) {
                    return true;
                }
                rows[i][k] = false, cols[j][k] = false, boxes[i / 3][j / 3][k] = false;
            }
        }
        return false;
    }
};
