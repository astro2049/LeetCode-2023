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
        int i = 0, j = 1;
        int maxProfit = 0;
        while (j < prices.size()) {
            int profit = prices[j] - prices[i];
            maxProfit = max(profit, maxProfit);
            if (prices[i] < prices[j]) {
                j++;
            } else {
                i = j;
                j++;
            }
        }
        return maxProfit;
    }
};
