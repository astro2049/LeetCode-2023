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
