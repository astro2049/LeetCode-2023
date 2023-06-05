#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            if (res < INT_MIN / 10 || res > INT_MAX / 10) {
                return 0;
            } else {
                res = res * 10 + digit;
            }
        }
        return res;
    }
};
