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
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
            return a[0] < b[0];
        });
        vector<vector<int>> res = {intervals[0]};
        for (int i = 1; i < intervals.size(); i++) {
            auto &last = res.back();
            if (intervals[i][0] > last[1]) {
                res.push_back(intervals[i]);
            } else {
                last[1] = max(last[1], intervals[i][1]);
            }
        }
        return res;
    }
};

/**
 * https://leetcode.com/problems/merge-intervals/solutions/293571/c-why-do-i-get-runtime-error-depending-on-whenther-sort-comp-function-is-or/
 */
