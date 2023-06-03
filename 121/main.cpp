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
        int maxProfit = 0;
        for (int l = 0, r = 1; r < prices.size(); r++) {
            if (prices[r] > prices[l]) {
                maxProfit = max(maxProfit, prices[r] - prices[l]);
            } else {
                l = r;
            }
        }
        return maxProfit;
    }
};

class Solution1 {
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
