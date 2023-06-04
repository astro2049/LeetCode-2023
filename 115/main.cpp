#include <iostream>
#include "vector"
#include "unordered_map"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string s, t;
    vector<unordered_map<int, int>> dp;

    int numDistinct(string s, string t) {
        this->s = s;
        this->t = t;
        dp.resize(s.length());
        return dfs(0, 0);
    }

    int dfs(int i, int k) {
        if (k == t.length()) {
            return 1;
        } else if (i == s.length()) {
            return 0;
        } else if (dp[i].find(k) != dp[i].end()) {
            return dp[i][k];
        } else {
            int count = dfs(i + 1, k);
            if (s[i] == t[k]) {
                count += dfs(i + 1, k + 1);
            }
            dp[i][k] = count;
            return dp[i][k];
        }
    }
};
