#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 1 || nums[0] < nums.back()) {
            return nums[0];
        }
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (nums[mid] >= nums[0]) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return nums[i];
    }
};
