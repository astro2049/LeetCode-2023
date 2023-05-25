#include <iostream>
#include "vector"
#include "unordered_set"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int n;
    vector<vector<string>> res;
    vector<string> cur;
    unordered_set<int> cols, posDiags, negDiags;

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        dfs(0);
        return res;
    }

    void dfs(int r) {
        if (r == n) {
            res.push_back(cur);
            return;
        }
        for (int c = 0; c < n; c++) {
            if (cols.find(c) == cols.end() && posDiags.find(r + c) == posDiags.end() &&
                negDiags.find(r - c) == negDiags.end()) {
                string x(n, '.');
                x[c] = 'Q';
                cur.push_back(x);
                control(r, c);
                dfs(r + 1);
                unControl(r, c);
                cur.pop_back();
            }
        }
    }

    void control(int r, int c) {
        cols.insert(c);
        posDiags.insert(r + c);
        negDiags.insert(r - c);
    }

    void unControl(int r, int c) {
        cols.erase(c);
        posDiags.erase(r + c);
        negDiags.erase(r - c);
    }
};

class Solution1 {
public:
    int n;
    vector<vector<string>> res;
    vector<string> cur;
    vector<vector<bool>> seized;

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        seized = vector<vector<bool>>(n, vector<bool>(n));
        dfs(0);
        return res;
    }

    void dfs(int r) {
        if (r == n) {
            res.push_back(cur);
            return;
        }
        for (int c = 0; c < n; c++) {
            if (!seized[r][c]) {
                string x(n, '.');
                x[c] = 'Q';
                cur.push_back(x);
                vector<vector<bool>> cSeized = seized;
                control(r, c);
                dfs(r + 1);
                seized = cSeized; // uncontrol
                cur.pop_back();
            }
        }
    }

    void control(int r, int c) {
        for (int i = 0; i < n; i++) {
            seized[r][i] = true;
        }
        for (int i = 0; i < n; i++) {
            seized[i][c] = true;
        }
        for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
            seized[i][j] = true;
        }
        for (int i = r, j = c; i >= 0 && j < n; i--, j++) {
            seized[i][j] = true;
        }
        for (int i = r, j = c; i < n && j >= 0; i++, j--) {
            seized[i][j] = true;
        }
        for (int i = r, j = c; i < n && j < n; i++, j++) {
            seized[i][j] = true;
        }
    }
};
