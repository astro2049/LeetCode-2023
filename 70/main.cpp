#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } else {
            int ways;
            int pp = 1, p = 2;
            for (int i = 3; i <= n; i++) {
                ways = pp + p;
                pp = p;
                p = ways;
            }
            return ways;
        }
    }
};
