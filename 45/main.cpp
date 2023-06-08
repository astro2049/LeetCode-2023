#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int jump(vector<int> &nums) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1;) {
            count++;
            if (i + nums[i] >= nums.size() - 1) {
                i += nums[i];
            } else {
                int maxJ = -1, maxJump = -1;
                for (int j = i + 1; j <= i + nums[i]; j++) {
                    if (j + nums[j] > maxJump) {
                        maxJump = j + nums[j];
                        maxJ = j;
                    }
                }
                i = maxJ;
            }
        }
        return count;
    }
};
