#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        int i = 0, j = 0;
        int maxLen = 0;
        for (; j < nums.size() - 1;) {
            if (nums[j] < nums[j + 1]) {
                j++;
            } else {
                maxLen = max(j - i + 1, maxLen);
                j++;
                i = j;
            }
        }
        maxLen = max(j - i + 1, maxLen);
        return maxLen;
    }
};
