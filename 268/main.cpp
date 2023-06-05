#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int n = nums.size();
        int missing = 0;
        for (auto num: nums) {
            missing ^= num;
        }
        for (int i = 0; i <= n; i++) {
            missing ^= i;
        }
        return missing;
    }
};
