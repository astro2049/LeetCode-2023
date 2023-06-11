#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string smallestString(string s) {
        int l = 0, r = 1;
        bool foundL = false;
        for (; l < s.length() && r < s.length();) {
            if (s[l] == 'a') {
                l++;
            } else {
                foundL = true;
            }
            if (s[r] != 'a' || !foundL) {
                r++;
            } else {
                break;
            }
        }
        if (l == s.length()) {
            if (s.back() == 'a') {
                s.back() = 'z';
            } else {
                s.back()--;
            }
        }
        for (int i = l; i <= r - 1; i++) {
            s[i]--;
            if (s[i] == 'a' - 1) {
                s[i] = 'z';
            }
        }
        return s;
    }
};
