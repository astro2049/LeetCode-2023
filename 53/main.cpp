#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int sum = 0;
        for (int n: nums) {
            sum += n;
            maxSum = max(sum, maxSum);
            if (sum <= 0) {
                sum = 0;
            }
        }
        return maxSum;
    }
};
