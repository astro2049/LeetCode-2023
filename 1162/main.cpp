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
    queue<pair<int, int>> q;
    int n;

    int maxDistance(vector<vector<int>> &grid) {
        n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        if (q.size() == 0 || q.size() == n * n) {
            return -1;
        }
        int dis = 0;
        while (!q.empty()) {
            dis++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto coord = q.front();
                q.pop();
                int r = coord.first, c = coord.second;
                addCoord(grid, r - 1, c);
                addCoord(grid, r + 1, c);
                addCoord(grid, r, c - 1);
                addCoord(grid, r, c + 1);
            }
        }
        return dis - 1;
    }

    void addCoord(vector<vector<int>> &grid, int r, int c) {
        if (r < 0 || r == n || c < 0 || c == n || grid[r][c] != 0) {
            return;
        }
        q.push({r, c});
        grid[r][c] = -1;
    }
};
