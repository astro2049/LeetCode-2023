#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    long long maxScore(vector<int> &nums, int x) {
        long long maxS = -1;
        vector<long long> dp(nums.size());
        int lastEvenI = -1, lastOddI = -1;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (num % 2 == 0) {
                if (lastEvenI != -1 && lastOddI != -1) {
                    dp[i] = max(dp[lastEvenI], dp[lastOddI] - x);
                } else if (lastEvenI == -1 && lastOddI == -1) {
                    dp[i] = 0;
                } else if (lastEvenI == -1 && lastOddI != -1) {
                    dp[i] = dp[lastOddI] - x;
                } else {
                    dp[i] = dp[lastEvenI];
                }
                lastEvenI = i;
            } else {
                if (lastEvenI != -1 && lastOddI != -1) {
                    dp[i] = max(dp[lastEvenI] - x, dp[lastOddI]);
                } else if (lastEvenI == -1 && lastOddI == -1) {
                    dp[i] = 0;
                } else if (lastEvenI == -1 && lastOddI != -1) {
                    dp[i] = dp[lastOddI];
                } else {
                    dp[i] = dp[lastEvenI] - x;
                }
                lastOddI = i;
            }
            dp[i] += num;
            maxS = max(maxS, dp[i]);
        }
        return maxS;
    }
};
