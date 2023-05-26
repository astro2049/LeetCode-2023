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
    vector<vector<bool>> visited;

    void solve(vector<vector<char>> &board) {
        this->board = board;
        m = board.size(), n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n));
        for (int i = 0; i < n; i++) {
            dfs(0, i);
            dfs(m - 1, i);
        }
        for (int i = 0; i < m; i++) {
            dfs(i, 0);
            dfs(i, n - 1);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(int r, int c) {
        if (r < 0 || r == m || c < 0 || c == n || board[r][c] == 'X' || visited[r][c]) {
            return;
        }
        visited[r][c] = true;
        dfs(r - 1, c);
        dfs(r + 1, c);
        dfs(r, c - 1);
        dfs(r, c + 1);
    }
};
