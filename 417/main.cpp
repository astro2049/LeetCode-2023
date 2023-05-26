#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> heights;
    int m, n;
    vector<vector<bool>> visited;
    vector<vector<int>> highGrounds;

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        this->heights = heights;
        m = heights.size(), n = heights[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n));
        highGrounds = vector<vector<int>>(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            dfs(0, i, 0, i, 1);
        }
        for (int i = 0; i < m; i++) {
            dfs(i, 0, i, 0, 1);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < n; i++) {
            dfs(m - 1, i, m - 1, i, 2);
        }
        for (int i = 0; i < m; i++) {
            dfs(i, n - 1, i, n - 1, 2);
        }
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (highGrounds[i][j] == 3) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

    void dfs(int r, int c, int pr, int pc, int type) {
        if (r < 0 || r == m || c < 0 || c == n || heights[r][c] < heights[pr][pc] || visited[r][c]) {
            return;
        }
        visited[r][c] = true;
        highGrounds[r][c] += type;
        dfs(r - 1, c, r, c, type);
        dfs(r + 1, c, r, c, type);
        dfs(r, c - 1, r, c, type);
        dfs(r, c + 1, r, c, type);
    }
};
