#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int longestSubarray(vector<int> &nums) {
        int maxLen = 0;
        int zeroCount = nums[0] == 0;
        for (int i = 0, j = 0;;) {
            if (zeroCount <= 1) {
                maxLen = max(maxLen, j - i);
                j++;
                if (j == nums.size()) {
                    break;
                }
                if (nums[j] == 0) {
                    zeroCount++;
                }
            } else {
                if (nums[i] == 0) {
                    zeroCount--;
                }
                i++;
                if (i == nums.size()) {
                    break;
                }
            }
        }
        return maxLen;
    }
};
