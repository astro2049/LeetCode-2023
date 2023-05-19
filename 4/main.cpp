#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        if (nums2.size() < nums1.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size(), n = nums2.size(), half = (m + n) / 2;
        if (m == 0) {
            return n % 2 == 1 ? nums2[half] : (double) (nums2[half - 1] + nums2[half]) / 2;
        }
        int l = -1, r = m;
        while (l <= r) {
            int i = (l + r) / 2;
            int j = half - i - 2;
            int n1l = i >= 0 ? nums1[i] : INT_MIN, n1r = i + 1 <= m - 1 ? nums1[i + 1] : INT_MAX;
            int n2l = j >= 0 ? nums2[j] : INT_MIN, n2r = j + 1 <= n - 1 ? nums2[j + 1] : INT_MAX;
            if (n1l > n2r) {
                r = i - 1;
            } else if (n2l > n1r) {
                l = i + 1;
            } else {
                return (m + n) % 2 == 1 ? min(n1r, n2r) : (double) (max(n1l, n2l) + min(n1r, n2r)) / 2;
            }
        }
        return -1;
    }
};