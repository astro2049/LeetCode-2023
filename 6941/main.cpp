#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> nums;

    int minimumOperations(vector<int> &nums) {
        if (nums.size() == 1) {
            return 0;
        }
        this->nums = nums;
        return search(0, 1);
    }

    int search(int i, int max) {
        if (i == nums.size()) {
            return 0;
        }
        if (nums[i] > max) {
            return min(1 + search(i + 1, max), search(i + 1, nums[i]));
        } else if (nums[i] == max) {
            return search(i + 1, max);
        } else {
            return 1 + search(i + 1, max);
        }
    }
};
