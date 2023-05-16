#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isPalindrome(string sIn) {
        string s;
        for (char c: sIn) {
            if (c >= 'A' && c <= 'Z') {
                s += c - ('A' - 'a');
            } else if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                s += c;
            }
        }
        for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};
