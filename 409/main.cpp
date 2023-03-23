#include <iostream>
#include "string"
#include "unordered_map"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for (char c: s) {
            m[c]++;
        }
        bool hasOdd = false;
        int len = 0;
        for (auto e: m) {
            if (e.second % 2 == 0) {
                len += e.second;
            } else {
                len += e.second - 1;
                hasOdd = true;
            }
        }
        if (hasOdd) {
            len++;
        }
        return len;
    }
};
