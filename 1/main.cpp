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
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            auto x = map.find(target - n);
            if (x != map.end()) {
                return {x->second, i};
            } else {
                map.insert({n, i});
            }
        }
        return {};
    }
};
