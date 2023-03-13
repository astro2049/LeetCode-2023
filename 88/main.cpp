#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        vector<int> nums;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                nums.push_back(nums1[i]);
                i++;
            } else {
                nums.push_back(nums2[j]);
                j++;
            }
        }
        if (i < m) {
            while (i < m) {
                nums.push_back(nums1[i]);
                i++;
            }
        }
        if (j < n) {
            while (j < n) {
                nums.push_back(nums2[j]);
                j++;
            }
        }
        nums1 = nums;
    }
};
