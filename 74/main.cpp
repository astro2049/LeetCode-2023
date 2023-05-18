#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = m - 1;
        while (i <= j) {
            int mid = (j - i) / 2 + i;
            if (matrix[mid][n - 1] < target) {
                i = mid + 1;
            } else if (matrix[mid][0] > target) {
                j = mid - 1;
            } else {
                break;
            }
        }
        if (i > j) {
            return false;
        }
        int rowN = (j - i) / 2 + i;
        i = 0, j = n - 1;
        while (i <= j) {
            int mid = (j - i) / 2 + i;
            if (matrix[rowN][mid] < target) {
                i = mid + 1;
            } else if (matrix[rowN][mid] > target) {
                j = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
