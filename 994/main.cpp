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
    int orangesRotting(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if (fresh == 0) {
            return 0;
        }
        int minutes = -1;
        vector<vector<int>> directions = {{-1, 0},
                                          {1,  0},
                                          {0,  -1},
                                          {0,  1}};
        while (!q.empty()) {
            minutes++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                int r = p.first, c = p.second;
                q.pop();
                for (auto d: directions) {
                    int dr = r + d[0], dc = c + d[1];
                    if (dr < 0 || dr == m || dc < 0 || dc == n || grid[dr][dc] != 1) {
                        continue;
                    }
                    grid[dr][dc] = 2;
                    fresh--;
                    q.push({dr, dc});
                }
            }
        }
        return fresh == 0 ? minutes : -1;
    }
};
