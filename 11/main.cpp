#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxAmount = 0;
        int i = 0, j = height.size() - 1;
        for (; i < j;) {
            int amount = (j - i) * min(height[i], height[j]);
            maxAmount = max(maxAmount, amount);
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return maxAmount;
    }
};
