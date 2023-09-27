#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int minSum = triangle[0][0];
        vector<int> upRow{triangle[0][0]};
        for (int i = 1; i < triangle.size(); i++) {
            int count = triangle[i].size();
            vector<int> row(count);
            int rowMinSum = INT_MAX;
            for (int j = 0; j < count; j++) {
                row[j] = triangle[i][j];
                if (j != 0 && j != count - 1) {
                    row[j] += min(upRow[j - 1], upRow[j]);
                } else if (j == 0) {
                    row[j] += upRow[j];
                } else {
                    row[j] += upRow[j - 1];
                }
                rowMinSum = min(rowMinSum, row[j]);
            }
            minSum = rowMinSum;
            upRow = row;
        }
        return minSum;
    }
};
