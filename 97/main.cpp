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
    string s1, s2, s3;
    unordered_map<string, int> dp;

    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1, this->s2 = s2, this->s3 = s3;
        return dfs(0, 0, 0);
    }

    bool dfs(int i, int j, int k) {
        string key = to_string(i) + "-" + to_string(j) + "-" + to_string(k);
        if (k == s3.length()) {
            return i == s1.length() && j == s2.length();
        } else if (dp.find(key) != dp.end()) {
            return dp[key];
        } else {
            if (s1[i] != s3[k] && s2[j] != s3[k]) {
                return false;
            } else if (s1[i] == s3[k] && s2[j] == s3[k]) {
                dp[key] = dfs(i, j + 1, k + 1) || dfs(i + 1, j, k + 1);
            } else if (s1[i] == s3[k]) {
                dp[key] = dfs(i + 1, j, k + 1);
            } else {
                dp[key] = dfs(i, j + 1, k + 1);
            }
            return dp[key];
        }
    }
};
