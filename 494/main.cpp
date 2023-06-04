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
    vector<int> nums;
    int target;
    vector<unordered_map<int, int>> dp;

    int findTargetSumWays(vector<int> &nums, int target) {
        this->nums = nums;
        this->target = target;
        dp.resize(nums.size());
        return dfs(0, 0);
    }

    int dfs(int i, int sum) {
        if (i == nums.size()) {
            return sum == target;
        } else if (dp[i].find(sum) != dp[i].end()) {
            return dp[i][sum];
        } else {
            dp[i][sum] = dfs(i + 1, sum - nums[i]) + dfs(i + 1, sum + nums[i]);
            return dp[i][sum];
        }
    }
};
