#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }
        vector<int> dp(n);
        dp[0] = 1, dp[1] = 2;
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp.back();
    }
};

class Solution1 {
public:
    int k = 0;
    int n;
    vector<int> dp;

    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        this->n = n;
        dp = vector<int>(n);
        dp[n - 1] = 1, dp[n - 2] = 2;
        return dfs(0);
    }

    int dfs(int i) {
        if (i == n - 1) {
            return 1;
        } else if (i == n - 2) {
            return 2;
        }
        if (dp[i + 1] == 0) {
            dp[i + 1] = dfs(i + 1);
        }
        if (dp[i + 2] == 0) {
            dp[i + 2] = dfs(i + 2);
        }
        return dp[i + 1] + dp[i + 2];
    }
};

class Solution2 {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } else {
            int ways;
            int pp = 1, p = 2;
            for (int i = 3; i <= n; i++) {
                ways = pp + p;
                pp = p;
                p = ways;
            }
            return ways;
        }
    }
};
