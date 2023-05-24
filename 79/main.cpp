#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int m, n;
    vector<vector<char>> board;
    string word;
    vector<vector<bool>> s;

    bool exist(vector<vector<char>> &board, string word) {
        this->board = board;
        this->word = word;
        m = board.size(), n = board[0].size();
        s = vector<vector<bool>>(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int r, int c, int i) {
        if (i == word.length()) {
            return true;
        }
        if (r < 0 || r == m || c < 0 || c == n || board[r][c] != word[i] || s[r][c]) {
            return false;
        }
        s[r][c] = true;
        bool res = dfs(r - 1, c, i + 1)
                   || dfs(r + 1, c, i + 1)
                   || dfs(r, c - 1, i + 1)
                   || dfs(r, c + 1, i + 1);
        s[r][c] = false;
        return res;
    }
};
