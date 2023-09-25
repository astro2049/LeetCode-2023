#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> up(m, vector<int>(n)), left = up, right = up, down = up;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'W') {
                    up[i][j] = 0;
                    left[i][j] = 0;
                } else {
                    up[i][j] = i != 0 ? up[i - 1][j] : 0;
                    left[i][j] = j != 0 ? left[i][j - 1] : 0;
                    if (grid[i][j] == 'E') {
                        up[i][j]++;
                        left[i][j]++;
                    }
                }
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 'W') {
                    down[i][j] = 0;
                    right[i][j] = 0;
                } else {
                    down[i][j] = i != m - 1 ? down[i + 1][j] : 0;
                    right[i][j] = j != n - 1 ? right[i][j + 1] : 0;
                    if (grid[i][j] == 'E') {
                        down[i][j]++;
                        right[i][j]++;
                    }
                }
            }
        }
        int maxKills = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') {
                    maxKills = max(maxKills, up[i][j] + left[i][j] + right[i][j] + down[i][j]);
                }
            }
        }
        return maxKills;
    }
};
