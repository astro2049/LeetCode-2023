#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int i = 1, j = *max_element(piles.begin(), piles.end());
        int minS = -1;
        while (i <= j) {
            int mid = (i + j) / 2;
            int time = h;
            bool expired = false;
            for (int p: piles) {
                time -= p % mid == 0 ? p / mid : p / mid + 1;
                if (time < 0) {
                    expired = true;
                    break;
                }
            }
            if (!expired) {
                minS = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return minS;
    }
};
