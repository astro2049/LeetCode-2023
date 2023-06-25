#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int> &nums) {
        long long a = 1, b = 0, mod = 1e9 + 7;
        bool has1 = false, oneOnLeft = false;
        for (int num: nums) {
            if (num == 1) {
                has1 = true;
                if (!oneOnLeft) {
                    oneOnLeft = true;
                    b++;
                } else {
                    a = (a * b) % mod;
                    b = 1;
                }
            } else {
                if (!oneOnLeft) {
                    continue;
                } else {
                    b++;
                }
            }
        }
        return has1 ? a : 0;
    }
};
