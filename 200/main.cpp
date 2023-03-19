#include <iostream>
#include "vector"
#include "queue"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;
    int num = 0;

    int numIslands(vector<vector<char>> &grid) {
        m = grid.size(), n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    num++;
                    bfs(grid, i, j);
                }
            }
        }
        return num;
    }

    void bfs(vector<vector<char>> &grid, int x, int y) {
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            auto coord = q.front();
            q.pop();
            int j = coord.first, k = coord.second;
            if (j < 0 || j >= m || k < 0 || k >= n || visited[j][k]) {
                continue;
            }
            if (grid[j][k] == '0') {
                continue;
            }
            visited[j][k] = true;
            q.push({j + 1, k});
            q.push({j - 1, k});
            q.push({j, k + 1});
            q.push({j, k - 1});
        }
    }
};
