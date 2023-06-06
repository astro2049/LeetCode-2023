#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        reverse(digits.begin(), digits.end());
        digits.push_back(0);
        digits[0]++;
        for (int i = 0; i < digits.size() - 1; i++) {
            if (digits[i] == 10) {
                digits[i] -= 10;
                digits[i + 1]++;
            }
        }
        if (digits.back() == 0) {
            digits.pop_back();
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
