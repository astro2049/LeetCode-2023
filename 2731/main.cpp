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
    int sumDistance(vector<int> &nums, string s, int d) {
        const int mod = 1e9 + 7;
        vector<long long> robots(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            robots[i] = nums[i];
            if (s[i] == 'L') {
                robots[i] -= d;
            } else {
                robots[i] += d;
            }
        }
        sort(robots.begin(), robots.end());
        long long res = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            res = (res + robots[i] * i - sum) % mod;
            sum = (sum + robots[i]) % mod;
        }
        return res;
    }
};
