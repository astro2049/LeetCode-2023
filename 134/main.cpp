#include <iostream>
#include "vector"
#include "numeric"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }
        int sum = 0, res = 0;
        for (int i = 0; i < gas.size(); i++) {
            sum += gas[i] - cost[i];
            if (sum < 0) {
                res = i + 1;
                sum = 0;
            }
        }
        return res;
    }
};
