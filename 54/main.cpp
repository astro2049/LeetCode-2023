#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> res;
    vector<vector<int>> directions = {{0,  1},
                                      {1,  0},
                                      {0,  -1},
                                      {-1, 0}};
    vector<vector<int>> matrix;
    int m, n;

    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        this->matrix = matrix;
        m = matrix.size(), n = matrix[0].size();
        dfs(0, 0, 0);
        return res;
    }

    void dfs(int r, int c, int i) {
        res.push_back(matrix[r][c]);
        matrix[r][c] = 101;
        int dr = r + directions[i][0], dc = c + directions[i][1];
        if (dr >= 0 && dr < m && dc >= 0 && dc < n && matrix[dr][dc] != 101) {
            dfs(dr, dc, i);
        } else {
            i++;
            if (i == 4) {
                i = 0;
            }
            dr = r + directions[i][0], dc = c + directions[i][1];
            if (dr >= 0 && dr < m && dc >= 0 && dc < n && matrix[dr][dc] != 101) {
                dfs(dr, dc, i);
            } else {
                return;
            }
        }
    }
};
