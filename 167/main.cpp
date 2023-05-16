#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] > target) {
                j--;
            } else if (numbers[i] + numbers[j] < target) {
                i++;
            } else {
                return {i + 1, j + 1};
            }
        }
        return {};
    }
};

class Solution1 {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            int supple = target - numbers[i];
            int supI = binarySearch(supple, i + 1, numbers);
            if (supI == -1) {
                continue;
            } else {
                return {i + 1, supI + 1};
            }
        }
        return {};
    }

    int binarySearch(int target, int i, vector<int> nums) {
        int j = nums.size() - 1;
        while (i <= j) {
            int mid = (j - i) / 2 + i;
            if (nums[mid] < target) {
                i = mid + 1;
            } else if (nums[mid] > target) {
                j = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
