#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int n_row = nums1.size(), n_col = nums2.size();
        vector<vector<int>> dp(n_row + 1, vector<int>(n_col + 1));
        int res = 0;
        for (int i = n_row - 1; i >= 0; i--) {
            for (int j = n_col - 1; j >= 0; j--) {
                dp[i][j] = nums1[i] == nums2[j] ? 1 + dp[i + 1][j + 1] : 0;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
