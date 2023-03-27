#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            int p = 0, c = 1;
            for (int i = 2; i <= n; i++) {
                int x = p + c;
                p = c;
                c = x;
            }
            return c;
        }
    }
};
