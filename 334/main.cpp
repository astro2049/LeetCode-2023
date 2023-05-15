#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        int first = nums[0], second = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int third = nums[i];
            if (third > second) {
                return true;
            } else if (third > first) {
                second = third;
            } else {
                first = third;
            }
        }
        return false;
    }
};
