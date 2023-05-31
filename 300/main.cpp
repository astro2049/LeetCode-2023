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
    int lengthOfLIS(vector<int> &nums) {
        vector<int> dp(nums.size(), 1);
        int len = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] < nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    len = max(len, dp[i]);
                }
            }
        }
        return len;
    }
};

class Solution1 {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> v(nums.size(), 1);
        for (int i = nums.size() - 2; i >= 0; i--) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] < nums[j]) {
                    v[i] = max(v[i], 1 + v[j]);
                }
            }
        }
        return *max_element(v.begin(), v.end());
    }
};
