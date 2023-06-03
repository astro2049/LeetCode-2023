#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> dp;
    vector<int> prices;

    int maxProfit(vector<int> &prices) {
        this->prices = prices;
        dp.resize(prices.size(), vector<int>(4, -1));
        return dfs(0, 0);
    }

    int dfs(int i, int mode) {
        if (i == prices.size()) {
            return 0;
        } else if (dp[i][mode] != -1) {
            return dp[i][mode];
        } else {
            int skip = dfs(i + 1, mode);
            int choice;
            if (mode == 0) { // buy1
                choice = dfs(i + 1, 1) - prices[i];
            } else if (mode == 1) {
                choice = dfs(i + 1, 2) + prices[i];
            } else if (mode == 2) {
                choice = dfs(i + 1, 3) - prices[i];
            } else {
                choice = prices[i];
            }
            dp[i][mode] = max(choice, skip);
            return dp[i][mode];
        }
    }
};
