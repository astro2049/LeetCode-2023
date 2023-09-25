#include <iostream>
#include "vector"
#include "unordered_set"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        for (int i = 0; i <= m - 3; i++) {
            for (int j = 0; j <= n - 3; j++) {
                if (isMagic(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }

    bool isMagic(vector<vector<int>> &grid, int i, int j) {
        if (grid[i + 1][j + 1] != 5) {
            return false;
        }
        unordered_set<int> s;
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                int num = grid[i + k][j + l];
                if (num >= 1 && num <= 9) {
                    s.insert(num);
                }
            }
        }
        return s.size() == 9 &&
               grid[i][j] + grid[i][j + 1] + grid[i][j + 2] == 15 &&
               grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2] == 15 &&
               grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2] == 15 &&
               grid[i][j] + grid[i + 1][j] + grid[i + 2][j] == 15 &&
               grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1] == 15 &&
               grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2] == 15 &&
               grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] == 15 &&
               grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2] == 15;
    }
};
