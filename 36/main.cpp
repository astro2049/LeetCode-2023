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
    bool isValidSudoku(vector<vector<char>> &board) {
        unordered_set<char> set;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (set.find(board[i][j]) == set.end()) {
                    set.insert(board[i][j]);
                } else {
                    return false;
                }
            }
            set.clear();
        }
        set.clear();
        for (int j = 0; j < 9; j++) {
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (set.find(board[i][j]) == set.end()) {
                    set.insert(board[i][j]);
                } else {
                    return false;
                }
            }
            set.clear();
        }
        set.clear();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (board[i * 3 + k][j * 3 + l] == '.') {
                            continue;
                        }
                        if (set.find(board[i * 3 + k][j * 3 + l]) == set.end()) {
                            set.insert(board[i * 3 + k][j * 3 + l]);
                        } else {
                            return false;
                        }
                    }
                }
                set.clear();
            }
        }
        return true;
    }
};
