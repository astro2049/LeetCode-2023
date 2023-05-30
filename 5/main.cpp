#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string longestPalindrome(string s) {
        int left;
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            int l = i, r = i;
            for (; l >= 0 && r < s.length(); l--, r++) {
                if (s[l] != s[r]) {
                    break;
                }
                if (r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    left = l;
                }
                maxLen = max(maxLen, r - l + 1);
            }
            l = i, r = i + 1;
            for (; l >= 0 && r < s.length(); l--, r++) {
                if (s[l] != s[r]) {
                    break;
                }
                if (r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    left = l;
                }
            }
        }
        return s.substr(left, maxLen);
    }
};
