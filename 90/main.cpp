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
    vector<int> nums;
    vector<vector<int>> r;

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        vector<int> subSet;
        dfs(0, subSet);
        return r;
    }

    void dfs(int i, vector<int> subSet) {
        if (i == nums.size()) {
            r.push_back(subSet);
            return;
        }
        subSet.push_back(nums[i]);
        dfs(i + 1, subSet);
        subSet.pop_back();
        i++;
        while (i < nums.size() && nums[i - 1] == nums[i]) {
            i++;
        }
        dfs(i, subSet);
    }
};
