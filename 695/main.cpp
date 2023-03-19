#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int area;
    int maxArea = 0;
    vector<vector<bool>> visited;
    int m, n;

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        m = grid.size(), n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    area = 0;
                    dfs(grid, i, j);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }

    void dfs(vector<vector<int>> &grid, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c]) {
            return;
        }
        visited[r][c] = true;
        if (grid[r][c] == 1) {
            area++;
            dfs(grid, r + 1, c);
            dfs(grid, r - 1, c);
            dfs(grid, r, c + 1);
            dfs(grid, r, c - 1);
        } else {
            return;
        }
    }
};
