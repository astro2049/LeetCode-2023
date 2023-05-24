#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> candidates;
    int target;
    vector<vector<int>> combs;
    vector<int> cur;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        this->candidates = candidates;
        this->target = target;
        dfs(0, 0);
        return combs;
    }

    void dfs(int i, int sum) {
        if (sum == target) {
            combs.push_back(cur);
            return;
        }
        if (i == candidates.size() || sum > target) {
            return;
        }
        cur.push_back(candidates[i]);
        dfs(i, sum + candidates[i]);
        cur.pop_back();
        dfs(i + 1, sum);
    }
};
