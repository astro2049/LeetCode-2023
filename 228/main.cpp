#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> ranges;
        for (int i = 0, j = i; i < nums.size() && j < nums.size();) {
            if (j == nums.size() - 1 || nums[j] + 1 != nums[j + 1]) {
                if (i == j) {
                    ranges.emplace_back(to_string(nums[i]));
                } else {
                    ranges.emplace_back(to_string(nums[i]) + "->" + to_string(nums[j]));
                }
                i = j + 1;
                j = i;
            } else {
                j++;
            }
        }
        return ranges;
    }
};
