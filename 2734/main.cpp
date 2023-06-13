#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string smallestString(string s) {
        int i = 0;
        for (; i < s.length(); i++) {
            if (s[i] != 'a') {
                break;
            }
        }
        bool operated = false;
        if (i < s.length()) {
            for (int j = i; j < s.length(); j++) {
                if (s[j] != 'a') {
                    operated = true;
                    s[j]--;
                } else {
                    break;
                }
            }
        }
        if (!operated) {
            if (s.back() == 'a') {
                s.back() = 'z';
            } else {
                s.back()--;
            }
        }
        return s;
    }
};

class Solution1 {
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
