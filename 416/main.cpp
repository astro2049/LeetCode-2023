#include <iostream>
#include "vector"
#include "unordered_set"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        unordered_set<int> s;
        int sum = 0;
        for (auto n: nums) {
            sum += n;
        }
        if (sum % 2 == 1) {
            return false;
        }
        sum /= 2;
        s.insert(0);
        for (int num: nums) {
            unordered_set<int> ns = s;
            for (auto x: s) {
                int sumX = x + num;
                if (sumX == sum) {
                    return true;
                } else {
                    ns.insert(x + num);
                }
            }
            s = ns;
        }
        return false;
    }
};
