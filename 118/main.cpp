#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ta = {{1}};
        for (int i = 1; i < numRows; i++) {
            vector<int> row = {1};
            for (int j = 1; j < i; j++) {
                row.push_back(ta[i - 1][j - 1] + ta[i - 1][j]);
            }
            row.push_back(1);
            ta.push_back(row);
        }
        return ta;
    }
};