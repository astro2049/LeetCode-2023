#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> matrix;
    int m, n;

    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        this->matrix = matrix;
        m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < n; i++) {
            if (!goodDiag(0, i)) {
                return false;
            }
        }
        for (int i = 1; i < m; i++) {
            if (!goodDiag(i, 0)) {
                return false;
            }
        }
        return true;
    }

    bool goodDiag(int i, int j) {
        for (int k = i + 1; k < m; k++) {
            for (int l = j + 1; l < n; l++) {
                if (matrix[k][l] == matrix[k - 1][l - 1]) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
