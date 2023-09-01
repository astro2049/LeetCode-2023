#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> vicinity = {
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0,  -1},
            {0,  1},
            {1,  -1},
            {1,  0},
            {1,  1},
    };
    int m, n;

    void gameOfLife(vector<vector<int>> &board) {
        m = board.size(), n = board[0].size();
        auto next = board;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = liveCells(board, i, j);
                if (board[i][j] == 1) {
                    if (live < 2 || live > 3) {
                        next[i][j] = 0;
                    }
                } else {
                    if (live == 3) {
                        next[i][j] = 1;
                    }
                }
            }
        }
        board = next;
    }

    int liveCells(vector<vector<int>> &board, int i, int j) {
        int count = 0;
        for (int k = 0; k < 8; k++) {
            int ii = i + vicinity[k][0], jj = j + vicinity[k][1];
            if (ii < 0 || ii == m || jj < 0 || jj == n) {
                continue;
            } else {
                count += board[ii][jj] == 1;
            }
        }
        return count;
    }
};
