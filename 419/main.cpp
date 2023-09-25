#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<char>> board;
    int m, n;

    int countBattleships(vector<vector<char>> &board) {
        this->board = board;
        m = board.size(), n = board[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (this->board[i][j] == 'X') {
                    count++;
                    dfs(i, j);
                }
            }
        }
        return count;
    }

    void dfs(int i, int j) {
        if (i < 0 || i == m || j < 0 || j == n || board[i][j] == '.') {
            return;
        }
        board[i][j] = '.';
        dfs(i - 1, j);
        dfs(i, j - 1);
        dfs(i, j + 1);
        dfs(i + 1, j);
    }
};
