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
    vector<int> candidates;
    int target;
    vector<vector<int>> res;
    vector<int> c;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        this->target = target;
        dfs(0, 0);
        return res;
    }

    void dfs(int i, int sum) {
        if (sum == target) {
            res.push_back(c);
            return;
        } else if (i == candidates.size() || sum > target) {
            return;
        } else {
            c.push_back(candidates[i]);
            dfs(i + 1, sum + candidates[i]);
            c.pop_back();
            for (i++; i < candidates.size() && candidates[i - 1] == candidates[i]; i++) {
            }
            dfs(i, sum);
        }
    }
};

class Solution1 {
public:
    vector<int> candidates;
    int target;
    vector<vector<int>> res;
    vector<int> cur;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        this->target = target;
        dfs(0, 0);
        return res;
    }

    void dfs(int i, int sum) {
        if (sum == target) {
            res.push_back(cur);
            return;
        }
        if (i == candidates.size() || sum > target) {
            return;
        }
        cur.push_back(candidates[i]);
        dfs(i + 1, sum + candidates[i]);
        cur.pop_back();
        for (i++; i < candidates.size() && candidates[i - 1] == candidates[i]; i++) {
        }
        dfs(i, sum);
    }
};
