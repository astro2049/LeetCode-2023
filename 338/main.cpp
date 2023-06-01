#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        int powerOf2 = 1;
        for (int i = 1; i <= n; i++) {
            if (powerOf2 * 2 == i) {
                powerOf2 = i;
            }
            dp[i] = 1 + dp[i - powerOf2];
        }
        return dp;
    }
};
