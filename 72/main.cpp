#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string word1, word2;
    vector<vector<int>> dp;

    int minDistance(string word1, string word2) {
        this->word1 = word1;
        this->word2 = word2;
        dp.resize(word1.length(), vector<int>(word2.length(), -1));
        return dfs(0, 0);
    }

    int dfs(int i, int j) {
        if (i == word1.length()) {
            return word2.length() - j;
        } else if (j == word2.length()) {
            return word1.length() - i;
        } else if (dp[i][j] != -1) {
            return dp[i][j];
        } else {
            if (word1[i] == word2[j]) {
                dp[i][j] = dfs(i + 1, j + 1);
            } else {
                dp[i][j] = 1 + min({dfs(i, j + 1), dfs(i + 1, j), dfs(i + 1, j + 1)});
            }
            return dp[i][j];
        }
    }
};
