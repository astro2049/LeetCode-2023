#include <iostream>
#include "vector"
#include "set"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> relocateMarbles(vector<int> &nums, vector<int> &moveFrom, vector<int> &moveTo) {
        set<int> s(nums.begin(), nums.end());
        for (int i = 0; i < moveFrom.size(); i++) {
            int from = moveFrom[i], to = moveTo[i];
            s.erase(from);
            s.insert(to);
        }
        return {s.begin(), s.end()};
    }
};
