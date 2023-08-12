#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string x;
        int step = numRows * 2 - 2;
        for (int i = 0; i < numRows; i++) {
            if (i == 0 || i == numRows - 1) {
                for (int j = i; j < s.length(); j += step) {
                    x += s[j];
                }
            } else {
                for (int j = i, k = step - j; j < s.length() || k < s.length(); j += step, k += step) {
                    if (j < s.length()) {
                        x += s[j];
                    }
                    if (k < s.length() & k != j) {
                        x += s[k];
                    }
                }
            }
        }
        return x;
    }
};
