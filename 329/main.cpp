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
    vector<vector<int>> matrix;
    int m, n;
    vector<vector<int>> dp;

    int longestIncreasingPath(vector<vector<int>> &matrix) {
        this->matrix = matrix;
        m = matrix.size(), n = matrix[0].size();
        dp.resize(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j, -1);
            }
        }
        int path = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                path = max(path, dp[i][j]);
            }
        }
        return path;
    }

    int dfs(int r, int c, int prev) {
        if (r < 0 || r == m || c < 0 || c == n || matrix[r][c] <= prev) {
            return 0;
        } else if (dp[r][c] != 0) {
            return dp[r][c];
        } else {
            dp[r][c] = 1 + max({
                                       dfs(r - 1, c, matrix[r][c]),
                                       dfs(r + 1, c, matrix[r][c]),
                                       dfs(r, c - 1, matrix[r][c]),
                                       dfs(r, c + 1, matrix[r][c])
                               });
            return dp[r][c];
        }
    }
};
