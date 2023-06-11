#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int findNonMinOrMax(vector<int> &nums) {
        int nMin = INT_MAX, nMax = INT_MIN;
        for (auto n: nums) {
            nMin = min(nMin, n);
            nMax = max(nMax, n);
        }
        for (auto n: nums) {
            if (n != nMin && n != nMax) {
                return n;
            }
        }
        return -1;
    }
};
