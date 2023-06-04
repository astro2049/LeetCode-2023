#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int semiOrderedPermutation(vector<int> &nums) {
        int n = nums.size();
        int i1, in;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                i1 = i;
            } else if (nums[i] == n) {
                in = i;
            }
        }
        int count = i1 + n - 1 - in;
        if (i1 > in) {
            count--;
        }
        return count;
    }
};
