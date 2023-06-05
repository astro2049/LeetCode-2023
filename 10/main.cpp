#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string s, p;
    vector<vector<int>> dp;

    bool isMatch(string s, string p) {
        this->s = s, this->p = p;
        dp.resize(s.length() + 1, vector<int>(p.length() + 1, -1));
        return dfs(0, 0);
    }

    bool dfs(int i, int j) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (i == s.length() && j == p.length()) {
            return true;
        } else if (j == p.length()) {
            return false;
        } else if (i == s.length()) {
            return j + 1 < p.length() && p[j + 1] == '*' && dfs(i, j + 2);
        } else {
            bool match = s[i] == p[j] || p[j] == '.';
            if (j + 1 < p.length() && p[j + 1] == '*') {
                if (match) {
                    dp[i][j] = dfs(i + 1, j) || dfs(i + 1, j + 2) || dfs(i, j + 2);
                } else {
                    dp[i][j] = dfs(i, j + 2);
                }
            } else {
                if (match) {
                    dp[i][j] = dfs(i + 1, j + 1);
                } else {
                    dp[i][j] = false;
                }
            }
            return dp[i][j];
        }
    }
};

class Solution1 {
public:
    string s, p;
    vector<vector<int>> dp;

    bool isMatch(string s, string p) {
        this->s = s, this->p = p;
        dp.resize(s.length() + 1, vector<int>(p.length() + 1, -1));
        return dfs(0, 0);
    }

    bool dfs(int i, int j) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        } else {
            if (i == s.length() && j == p.length()) {
                return true;
            } else if (i == s.length() && j < p.length()) {
                dp[i][j] = j + 1 < p.length() && p[j + 1] == '*' && dfs(i, j + 2);
                return dp[i][j];
            } else if (i < s.length() && j == p.length()) {
                return false;
            } else {
                if (p[j] >= 'a' && p[j] <= 'z') {
                    if (j + 1 < p.length() && p[j + 1] == '*') {
                        if (s[i] != p[j]) {
                            dp[i][j] = dfs(i, j + 2);
                        } else {
                            dp[i][j] = dfs(i, j + 2) || dfs(i + 1, j) || dfs(i + 1, j + 2);
                        }
                    } else {
                        if (s[i] != p[j]) {
                            dp[i][j] = false;
                        } else {
                            dp[i][j] = dfs(i + 1, j + 1);
                        }
                    }
                } else {
                    if (j + 1 < p.length() && p[j + 1] == '*') {
                        dp[i][j] = dfs(i, j + 2) || dfs(i + 1, j) || dfs(i + 1, j + 2);
                    } else {
                        dp[i][j] = dfs(i + 1, j + 1);
                    }
                }
            }
            return dp[i][j];
        }
    }
};
