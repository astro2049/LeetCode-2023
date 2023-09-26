#include <iostream>
#include "unordered_set"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    unordered_set<int> cols, downDiags, upDiags;
    int n;
    int solutions = 0;

    int totalNQueens(int n) {
        this->n = n;
        dfs(1);
        return solutions;
    }

    void dfs(int i) {
        if (i == n + 1) {
            solutions++;
            return;
        }
        int r = i - 1;
        for (int c = 0; c < n; c++) {
            if (cols.find(c) == cols.end() && downDiags.find(c - r) == downDiags.end() &&
                upDiags.find(r + c) == upDiags.end()) {
                cols.insert(c);
                downDiags.insert(c - r);
                upDiags.insert(r + c);
                dfs(i + 1);
                cols.erase(c);
                downDiags.erase(c - r);
                upDiags.erase(r + c);
            }
        }
    }
};
