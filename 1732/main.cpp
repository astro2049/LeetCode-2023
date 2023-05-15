#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int largestAltitude(vector<int> &gain) {
        int maxAlt = max(0, gain[0]);
        for (int i = 1; i < gain.size(); i++) {
            gain[i] += gain[i - 1];
            maxAlt = max(maxAlt, gain[i]);
        }
        return maxAlt;
    }
};
