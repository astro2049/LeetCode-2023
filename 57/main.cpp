#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &ni) {
        vector<vector<int>> res;
        int i = 0;
        for (; i < intervals.size(); i++) {
            auto interv = intervals[i];
            if (ni[1] < interv[0]) {
                res.push_back(ni);
                res.insert(res.end(), intervals.begin() + i, intervals.end());
                return res;
            } else if (ni[0] > interv[1]) {
                res.push_back(interv);
            } else {
                ni = {min(interv[0], ni[0]), max(interv[1], ni[1])};
            }
        }
        res.push_back(ni);
        return res;
    }
};
