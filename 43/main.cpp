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
    string multiply(string num1, string num2) {
        if (num1.length() < num2.length()) {
            return multiply(num2, num1);
        }
        vector<int> x(num1.length() + num2.length());
        reverse(num1.begin(), num1.end()), reverse(num2.begin(), num2.end());
        for (int i = 0; i < num2.length(); i++) {
            for (int j = 0; j < num1.length(); j++) {
                int p = (num2[i] - '0') * (num1[j] - '0');
                x[i + j] += p;
                x[i + j + 1] += x[i + j] / 10;
                x[i + j] %= 10;
            }
        }
        while (!x.empty() && x.back() == 0) {
            x.pop_back();
        }
        if (x.empty()) {
            return "0";
        }
        for (auto &num: x) {
            num += '0';
        }
        string res(x.begin(), x.end());
        reverse(res.begin(), res.end());
        return res;
    }
};
