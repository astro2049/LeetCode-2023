#include <iostream>
#include "vector"
#include "unordered_set"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        vector<int> diff1, diff2;
        for (int n1: s1) {
            if (s2.find(n1) == s2.end()) {
                diff1.push_back(n1);
            }
        }
        for (int n2: s2) {
            if (s1.find(n2) == s1.end()) {
                diff2.push_back(n2);
            }
        }
        return {diff1, diff2};
    }
};
