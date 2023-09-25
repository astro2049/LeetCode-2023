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
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum = INT_MAX / 2;
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > target) {
                    if (abs(sum - target) < abs(closestSum - target)) {
                        closestSum = sum;
                    }
                    k--;
                } else if (sum < target) {
                    if (abs(sum - target) < abs(closestSum - target)) {
                        closestSum = sum;
                    }
                    j++;
                } else {
                    return target;
                }
            }
        }
        return closestSum;
    }
};
