#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        int pp = 1, p = 1;
        for (int i = 1; i < s.length(); i++) {
            int c = 0;
            if (s[i] != '0') {
                c += p;
            }
            int x = stoi(s.substr(i - 1, 2));
            if (x >= 10 && x <= 26) {
                c += pp;
            }
            pp = p;
            p = c;
        }
        return p;
    }
};

class Solution1 { // TLE
public:
    string s;

    int numDecodings(string s) {
        this->s = s;
        return decode(0);
    }

    int decode(int i) {
        if (i == s.length()) {
            return 1;
        }
        if (s[i] == '0') {
            return 0;
        }
        int count = 0;
        if (s.length() - i >= 2) {
            int x = stoi(s.substr(i, 2));
            if (x >= 10 && x <= 26) {
                count += decode(i + 2);
            }
        }
        count += decode(i + 1);
        return count;
    }
};
