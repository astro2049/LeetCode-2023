#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> grid;
    int m, n;

    int islandPerimeter(vector<vector<int>> &grid) {
        this->grid = grid;
        m = grid.size(), n = grid[0].size();
        int perimeter = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    perimeter += cellPerimeter(i, j);
                }
            }
        }
        return perimeter;
    }

    int cellPerimeter(int i, int j) {
        int sum = 0;
        if (j == 0 || grid[i][j - 1] == 0) {
            sum++;
        }
        if (i == 0 || grid[i - 1][j] == 0) {
            sum++;
        }
        if (j == n - 1 || grid[i][j + 1] == 0) {
            sum++;
        }
        if (i == m - 1 || grid[i + 1][j] == 0) {
            sum++;
        }
        return sum;
    }
};
