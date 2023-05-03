#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
        int maxCan = 0;
        for (int candy: candies) {
            maxCan = max(candy, maxCan);
        }
        vector<bool> r;
        for (int candy: candies) {
            r.push_back(candy + extraCandies >= maxCan);
        }
        return r;
    }
};
