#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> p(n + 1);
        p[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            p[i] = nums[i] * p[i + 1];
        }
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            p[i] = prefix * p[i + 1];
            prefix *= nums[i];
        }
        p.pop_back();
        return p;
    }
};
