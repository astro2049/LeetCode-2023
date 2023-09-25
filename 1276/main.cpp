#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int twoTimesJumbo = tomatoSlices - 2 * cheeseSlices;
        if (twoTimesJumbo % 2 == 1) {
            return {};
        }
        int jumbo = twoTimesJumbo / 2;
        int small = cheeseSlices - jumbo;
        if (jumbo < 0 || small < 0) {
            return {};
        }
        return {jumbo, small};
    }
};
