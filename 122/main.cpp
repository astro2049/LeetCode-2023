#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        for (int l = 0, r = 1; r < prices.size(); r++) {
            if (prices[r - 1] > prices[r]) {
                profit += prices[r - 1] - prices[l];
                l = r;
            } else if (r == prices.size() - 1) {
                profit += prices[r] - prices[l];
            }
        }
        return profit;
    }
};
