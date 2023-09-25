#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int projectionArea(vector<vector<int>> &grid) {
        int area = 0;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    area++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int maxHeight = 0;
            for (int j = 0; j < n; j++) {
                maxHeight = max(maxHeight, grid[i][j]);
            }
            area += maxHeight;
        }
        for (int j = 0; j < n; j++) {
            int maxHeight = 0;
            for (int i = 0; i < n; i++) {
                maxHeight = max(maxHeight, grid[i][j]);
            }
            area += maxHeight;
        }
        return area;
    }
};
