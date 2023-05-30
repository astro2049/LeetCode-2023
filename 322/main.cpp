#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int minCount = INT_MAX;
            for (auto coin: coins) {
                if (i - coin >= 0) {
                    if (dp[i - coin] != -1) {
                        minCount = min(minCount, 1 + dp[i - coin]);
                    }
                }
            }
            dp[i] = minCount != INT_MAX ? minCount : -1;
        }
        return dp.back();
    }
};
