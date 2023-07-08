#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int alternatingSubarray(vector<int> &nums) {
        int maxLen = -1;
        int diff = 1;
        for (int i = 0; i < nums.size();) {
            int j = i + 1;
            for (; j < nums.size(); j++) {
                if (nums[j] - nums[j - 1] == diff) {
                    maxLen = max(maxLen, j - i + 1);
                    diff *= -1;
                } else {
                    i = max(i + 1, j - 1);
                    diff = 1;
                    break;
                }
            }
            if (j == nums.size()) {
                break;
            }
        }
        return maxLen;
    }
};
