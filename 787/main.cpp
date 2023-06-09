#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        for (int i = 0; i < k + 1; i++) {
            auto tmp = prices;
            for (auto flight: flights) {
                int s = flight[0], d = flight[1], p = flight[2];
                if (prices[s] == INT_MAX) {
                    continue;
                } else if (prices[s] + p < tmp[d]) {
                    tmp[d] = prices[s] + p;
                }
            }
            prices = tmp;
        }
        return prices[dst] != INT_MAX ? prices[dst] : -1;
    }
};
