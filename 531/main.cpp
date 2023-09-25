#include <iostream>
#include "vector"
#include "unordered_map"
#include "unordered_set"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int findLonelyPixel(vector<vector<char>> &picture) {
        int m = picture.size(), n = picture[0].size();
        unordered_map<int, unordered_set<int>> rows, cols;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (picture[i][j] == 'B') {
                    rows[i].insert(j);
                    cols[j].insert(i);
                }
            }
        }
        int count = 0;
        for (const auto &p: rows) {
            if (p.second.size() == 1) {
                int col = *p.second.begin();
                if (cols[col].size() == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};
