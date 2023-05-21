#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int s = 0, f = 0;
        while (true) {
            s = nums[s];
            f = nums[nums[f]];
            if (s == f) {
                break;
            }
        }
        int a = 0;
        while (true) {
            a = nums[a];
            s = nums[s];
            if (a == s) {
                break;
            }
        }
        return a;
    }
};
