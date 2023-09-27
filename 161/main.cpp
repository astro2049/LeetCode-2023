#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (abs(int(s.length() - t.length())) > 1) {
            return false;
        }
        int i = 0, j = 0;
        for (; i < s.length() && j < t.length(); i++, j++) {
            if (s[i] != t[j]) {
                break;
            }
        }
        if (i == s.length() && j == t.length()) {
            return false;
        }
        return isSame(s, t, i + 1, j) ||
               isSame(s, t, i, j + 1) ||
               isSame(s, t, i + 1, j + 1);
    }

    bool isSame(string &s, string &t, int i, int j) {
        for (; i < s.length() && j < t.length(); i++, j++) {
            if (s[i] != t[j]) {
                return false;
            }
        }
        return i == s.length() && j == t.length();
    }
};
