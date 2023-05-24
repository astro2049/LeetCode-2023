#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> nums;
    vector<vector<int>> r;
    vector<int> subSet;

    vector<vector<int>> subsets(vector<int> &nums) {
        this->nums = nums;
        dfs(0);
        return r;
    }

    void dfs(int i) {
        if (i == nums.size()) {
            r.push_back(subSet);
            return;
        }
        subSet.push_back(nums[i]);
        dfs(i + 1);
        subSet.pop_back();
        dfs(i + 1);
    }
};
