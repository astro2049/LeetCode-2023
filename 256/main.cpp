#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int minCost(vector<vector<int>> &houses) {
        vector<int> minCosts = {0, 0, 0};
        for (auto &house: houses) {
            vector<int> costs = {INT_MAX, INT_MAX, INT_MAX};
            for (int j = 0; j < 3; j++) {
                int k = 0;
                for (; k < 3; k++) {
                    if (k == j) {
                        continue;
                    } else {
                        costs[j] = min(costs[j], minCosts[k] + house[j]);
                    }
                }
            }
            minCosts = costs;
        }
        return *min_element(minCosts.begin(), minCosts.end());
    }
};
