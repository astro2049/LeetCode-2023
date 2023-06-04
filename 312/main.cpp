#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> nums;
    int n;
    vector<vector<int>> dp;

    int maxCoins(vector<int> &nums) {
        n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        this->nums = nums;
        dp.resize(n + 2, vector<int>(n + 2, -1));
        return dfs(1, n);
    }

    int dfs(int l, int r) {
        if (l > r) {
            return 0;
        } else if (dp[l][r] != -1) {
            return dp[l][r];
        } else {
            for (int i = l; i <= r; i++) {
                int coins = nums[l - 1] * nums[i] * nums[r + 1];
                coins += dfs(l, i - 1) + dfs(i + 1, r);
                dp[l][r] = max(dp[l][r], coins);
            }
            return dp[l][r];
        }
    }
};
