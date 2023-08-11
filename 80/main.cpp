#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 1) {
            return 1;
        }
        int l = 2;
        for (int r = 2; r < nums.size(); r++) {
            if (nums[l - 2] != nums[r]) {
                nums[l] = nums[r];
                l++;
            }
        }
        return l;
    }
};
