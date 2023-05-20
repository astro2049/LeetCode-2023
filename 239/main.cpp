#include <iostream>
#include "vector"
#include "deque"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> d;
        vector<int> maxs;
        for (int i = 0; i < k - 1; i++) {
            while (!d.empty() && nums[d.back()] <= nums[i]) {
                d.pop_back();
            }
            d.push_back(i);
        }
        for (int i = 0, j = k - 1; j < nums.size(); i++, j++) {
            if (!d.empty() && i > d.front()) {
                d.pop_front();
            }
            while (!d.empty() && nums[d.back()] <= nums[j]) {
                d.pop_back();
            }
            d.push_back(j);
            maxs.push_back(nums[d.front()]);
        }
        return maxs;
    }
};
