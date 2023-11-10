#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> potions;

    vector<int> successfulPairs(vector<int> &spells, vector<int> &aPotions, long long success) {
        potions = aPotions;
        sort(potions.begin(), potions.end());

        vector<int> pairs(spells.size());
        for (int i = 0; i < spells.size(); i++) {
            const int spell = spells[i];
            const long long minStrength = ceil((double) success / spell);
            if (minStrength > INT_MAX) {
                pairs[i] = 0;
                continue;
            }
            int index = binarySearch(minStrength);
            if (index == -1) {
                pairs[i] = 0;
                continue;
            }
            pairs[i] = potions.size() - index;
        }

        return pairs;
    }

    int binarySearch(int minStrength) {
        int i = 0, j = potions.size() - 1;
        int index = -1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (potions[mid] >= minStrength) {
                index = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return index;
    }
};
