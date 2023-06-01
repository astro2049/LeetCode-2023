#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int k;

    int findKthLargest(vector<int> &nums, int k) {
        this->k = nums.size() - k;
        srand(time(nullptr));
        return quickSelect(nums, 0, nums.size() - 1);
    }

    int quickSelect(vector<int> &nums, int l, int r) {
        int pivot = rand() % (r - l + 1) + l;
        swap(nums[r], nums[pivot]);
        pivot = r;
        int p = l;
        for (int i = l; i < r; i++) {
            if (nums[i] < nums[pivot]) {
                swap(nums[p], nums[i]);
                p++;
            }
        }
        swap(nums[p], nums[pivot]);
        if (p == k) {
            return nums[p];
        } else if (p < k) {
            return quickSelect(nums, p + 1, r);
        } else {
            return quickSelect(nums, l, p - 1);
        }
    }
};
