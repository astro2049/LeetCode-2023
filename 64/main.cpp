#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> upRow(n, -1);
        for (int i = 0; i < m; i++) {
            int left = -1;
            vector<int> sums(n);
            for (int j = 0; j < n; j++) {
                if (left != -1 && upRow[j] != -1) {
                    sums[j] = min(left, upRow[j]);
                } else if (upRow[j] != -1) {
                    sums[j] = upRow[j];
                } else if (left != -1) {
                    sums[j] = left;
                } else {
                    sums[j] = 0;
                }
                sums[j] += grid[i][j];
                left = sums[j];
            }
            upRow = sums;
        }
        return upRow.back();
    }
};
