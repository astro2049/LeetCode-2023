#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> prices;
    vector<vector<int>> dp;

    int maxProfit(vector<int> &prices) {
        this->prices = prices;
        dp.resize(prices.size(), vector<int>(2, -1));
        return dfs(0, true);
    }

    int dfs(int i, bool canBuy) {
        if (i >= prices.size()) {
            return 0;
        } else if (dp[i][canBuy] != -1) {
            return dp[i][canBuy];
        } else {
            int coolDown = dfs(i + 1, canBuy);
            if (canBuy) {
                int buy = dfs(i + 1, false) - prices[i];
                dp[i][canBuy] = max(buy, coolDown);
            } else {
                int sell = dfs(i + 2, true) + prices[i];
                dp[i][canBuy] = max(sell, coolDown);
            }
            return dp[i][canBuy];
        }
    }
};
