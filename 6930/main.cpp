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
    bool isGood(vector<int> &nums) {
        if (nums.size() < 2) {
            return false;
        }
        sort(nums.begin(), nums.end());
        if (nums.rbegin()[1] != nums.back()) {
            return false;
        }
        for (int i = nums.size() - 1 - 2; i >= 0; i--) {
            if (nums[i] + 1 == nums[i + 1]) {
                continue;
            } else {
                return false;
            }
        }
        return nums[0] == 1;
    }
};
