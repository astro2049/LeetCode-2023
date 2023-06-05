#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned int tmp = (unsigned int) (a & b) << 1;
            a = a ^ b;
            b = tmp;
        }
        return a;
    }
};
