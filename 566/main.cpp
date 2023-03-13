#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
        int p = mat.size(), q = mat[0].size();
        if (p * q != r * c) {
            return mat;
        }
        vector<vector<int>> m(r, vector<int>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                m[i][j] = mat[(i * c + j) / q][(i * c + j) % q];
            }
        }
        return m;
    }
};
