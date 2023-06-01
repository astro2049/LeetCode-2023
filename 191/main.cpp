#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int w = 0;
        for (int i = 0; i < 32; i++) {
            w += ((n & 1) == 1);
            n >>= 1;
        }
        return w;
    }
};
