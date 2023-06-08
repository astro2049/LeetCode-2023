#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
        vector<bool> res(3);
        for (auto &trip: triplets) {
            bool skip = false;
            for (int i = 0; i < 3; i++) {
                if (trip[i] > target[i]) {
                    skip = true;
                    break;
                }
            }
            if (skip) {
                continue;
            }
            for (int i = 0; i < 3; i++) {
                if (trip[i] == target[i]) {
                    res[i] = true;
                }
            }
            bool yes = true;
            for (int i = 0; i < 3; i++) {
                if (!res[i]) {
                    yes = false;
                    break;
                }
            }
            if (yes) {
                return true;
            }
        }
        return false;
    }
};
