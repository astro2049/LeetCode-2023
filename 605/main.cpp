#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        if (flowerbed.size() == 1) {
            if (flowerbed[0] == 0) {
                return 1 >= n;
            } else {
                return 0 >= n;
            }
        }
        int count = 0;
        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            count++;
            flowerbed[0] = 1;
        }
        for (int i = 1; i < flowerbed.size() - 1; i++) {
            if (i != 0 && i != flowerbed.size() - 1) {
                if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                    count++;
                    flowerbed[i] = 1;
                }
            }
        }
        if (flowerbed.back() == 0 && flowerbed.rbegin()[1] == 0) {
            count++;
        }
        return count >= n;
    }
};
