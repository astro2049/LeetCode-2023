#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> upRow(n);
        upRow[0] = 1;
        for (int i = 0; i < m; i++) {
            vector<int> ways(n);
            int left = 0;
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    ways[j] = upRow[j] + left;
                } else {
                    ways[j] = 0;
                }
                left = ways[j];
            }
            upRow = ways;
        }
        return upRow.back();
    }
};
