#include <iostream>
#include "vector"
#include "unordered_map"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> map1, map2;
        for (int n1: nums1) {
            auto x = map1.find(n1);
            if (x == map1.end()) {
                map1.insert({n1, 1});
            } else {
                map1[n1] += 1;
            }
        }
        for (int n2: nums2) {
            auto x = map2.find(n2);
            if (x == map2.end()) {
                map2.insert({n2, 1});
            } else {
                map2[n2] += 1;
            }
        }
        vector<int> res;
        for (auto m1: map1) {
            auto x = map2.find(m1.first);
            if (x != map2.end()) {
                int rep = min(m1.second, x->second);
                for (int i = 0; i < rep; i++) {
                    res.push_back(m1.first);
                }
            }
        }
        return res;
    }
};
