#include <iostream>
#include "vector"
#include "unordered_map"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class SparseVector {
public:
    unordered_map<int, int> m;

    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                m[i] = nums[i];
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector &vec) {
        int prod = 0;
        for (const auto &p: m) {
            int i = p.first, val = p.second;
            if (vec.m.find(i) != vec.m.end()) {
                prod += val * vec.m[i];
            }
        }
        return prod;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
