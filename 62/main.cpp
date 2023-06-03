#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n));
        grid[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] += (i == 0 ? 0 : grid[i - 1][j]) + (j == 0 ? 0 : grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};

class Solution1 {
public:
    int uniquePaths(int m, int n) {
        if (m == 1) {
            return 1;
        }
        vector<int> l(n, 1);
        vector<int> c(n);
        for (int i = 1; i < m; i++) {
            c[0] = 1;
            for (int j = 1; j < n; j++) {
                c[j] = c[j - 1] + l[j];
            }
            l = c;
        }
        return c.back();
    }
};
