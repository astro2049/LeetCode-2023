#include <iostream>
#include "vector"
#include "map"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        map<int, int> m;
        for (int num: nums) {
            m[num]++;
        }
        vector<pair<int, int>> v_m(m.begin(), m.end());
        sort(v_m.begin(), v_m.end(), [](const pair<int, int> e1, const pair<int, int> e2) {
            return e1.second > e2.second;
        });

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(v_m[i].first);
        }
        return res;
    }
};
