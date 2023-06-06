#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    double myPow(double x, int pn) {
        auto n = (long long) pn;
        if (n == 0) {
            return 1;
        } else if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        return dfs(x, n);
    }

    double dfs(double x, long long n) {
        if (n == 1) {
            return x;
        }
        double split = dfs(x, n / 2);
        double res = split * split;
        if (n % 2 == 1) {
            res *= x;
        }
        return res;
    }
};
