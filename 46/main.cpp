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
    vector<bool> used;
    vector<vector<int>> perms;
    vector<int> cur;

    vector<vector<int>> permute(vector<int> &nums) {
        this->nums = nums;
        used = vector<bool>(nums.size(), false);
        dfs();
        return perms;
    }

    void dfs() {
        if (cur.size() == nums.size()) {
            perms.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            } else {
                cur.push_back(nums[i]);
                used[i] = true;
                dfs();
                cur.pop_back();
                used[i] = false;
            }
        }
    }
};
