#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (target >= nums[0]) {
                if (nums[mid] >= nums[0]) {
                    if (target < nums[mid]) {
                        j = mid - 1;
                    } else if (target > nums[mid]) {
                        i = mid + 1;
                    } else {
                        return mid;
                    }
                } else {
                    j = mid - 1;
                }
            } else {
                if (nums[mid] <= nums.back()) {
                    if (target < nums[mid]) {
                        j = mid - 1;
                    } else if (target > nums[mid]) {
                        i = mid + 1;
                    } else {
                        return mid;
                    }
                } else {
                    i = mid + 1;
                }
            }
        }
        return -1;
    }
};
