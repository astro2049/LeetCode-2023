#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n_row = text1.length(), n_col = text2.length();
        vector<vector<int>> dp(n_row + 1, vector<int>(n_col + 1));
        for (int i = n_row - 1; i >= 0; i--) {
            for (int j = n_col - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};

class Solution0 {
public:
    string t1, t2;
    int n_row, n_col;

    int longestCommonSubsequence(string text1, string text2) {
        t1 = text1, t2 = text2;
        n_row = text1.length(), n_col = text2.length();
        vector<vector<int>> m(n_row, vector<int>(n_col));
        int r = 0, c = 0;
        return pairChars(r, c, 0, m);
    }

    int pairChars(int r, int c, int len, vector<vector<int>> &m) {
        if (r == n_row || c == n_col) {
            return len;
        }
        if (t1[r] == t2[c]) {
            return pairChars(r + 1, c + 1, len + 1, m);
        } else {
            return max(pairChars(r + 1, c, len, m), pairChars(r, c + 1, len, m));
        }
    }
}; // TLE


