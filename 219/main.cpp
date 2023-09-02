#include <iostream>
#include "vector"
#include "unordered_map"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size() && i <= k; i++) {
            m[nums[i]]++;
            if (m[nums[i]] == 2) {
                return true;
            }
        }
        for (int i = 0, j = k + 1; j < nums.size(); i++, j++) {
            m[nums[i]]--;
            m[nums[j]]++;
            if (m[nums[j]] == 2) {
                return true;
            }
        }
        return false;
    }
};
