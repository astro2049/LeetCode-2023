#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        int maxSum = 0, sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        maxSum = sum;
        for (int i = 0, j = k; j < nums.size(); i++, j++) {
            sum -= nums[i];
            sum += nums[j];
            maxSum = max(maxSum, sum);
        }
        return (double) maxSum / k;
    }
};
