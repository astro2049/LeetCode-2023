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
    int maxProduct(vector<int> &nums) {
        int res = *max_element(nums.begin(), nums.end());
        int curMax = 1, curMin = 1;
        for (auto n: nums) {
            if (n == 0) {
                curMax = 1, curMin = 1;
                continue;
            }
            int cMax = curMax;
            curMax = max({curMax * n, curMin * n, n});
            curMin = min({cMax * n, curMin * n, n});
            res = max(res, curMax);
        }
        return res;
    }
};
