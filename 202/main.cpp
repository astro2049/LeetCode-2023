#include <iostream>
#include "unordered_set"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (n != 1) {
            if (s.find(n) != s.end()) {
                return false;
            }
            s.insert(n);
            int sum = 0;
            string digits = to_string(n);
            for (auto d: digits) {
                sum += (d - '0') * (d - '0');
            }
            n = sum;
        }
        return true;
    }
};
