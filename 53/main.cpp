#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int maxSum = INT_MIN, sum = 0;
        for (int num: nums) {
            sum += num;
            maxSum = max(maxSum, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxSum;
    }
};

class Solution1 {
public:
    int maxSubArray(vector<int> &nums) {
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
