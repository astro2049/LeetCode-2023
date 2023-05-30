#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        vector<int> dp;
        dp.push_back(cost[0]);
        dp.push_back(cost[1]);
        for (int i = 2; i < cost.size(); i++) {
            dp.push_back(min(dp[i - 2], dp[i - 1]) + cost[i]);
        }
        return min(dp.rbegin()[1], dp.back());
    }
};

class Solution1 {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        int pp = cost[0], p = cost[1], c;
        for (int i = 2; i < n; i++) {
            c = min(pp, p) + cost[i];
            pp = p;
            p = c;
        }
        return min(pp, p);
    }
};
