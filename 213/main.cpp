#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int pp = 0, p = nums[0];
        for (int i = 1; i < nums.size() - 1; i++) {
            int c = max(pp + nums[i], p);
            pp = p;
            p = c;
        }
        int max1 = p;
        pp = 0, p = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            int c = max(pp + nums[i], p);
            pp = p;
            p = c;
        }
        int max2 = p;
        return max(max1, max2);
    }
};
