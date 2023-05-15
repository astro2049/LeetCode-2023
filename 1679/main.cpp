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
    int maxOperations(vector<int> &nums, int k) {
        unordered_map<int, int> m;
        for (int num: nums) {
            m[num]++;
        }
        int count = 0;
        for (auto pair: m) {
            int val = pair.first;
            if (val == k - val) {
                count += m[val] / 2;
                m[val] = 0;
            } else {
                if (m.find(k - val) != m.end()) {
                    count += min(m[val], m[k - val]);
                    m[val] = 0, m[k - val] = 0;
                }
            }
        }
        return count;
    }
};
