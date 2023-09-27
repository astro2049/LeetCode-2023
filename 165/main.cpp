#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int compareVersion(string &v1, string &v2) {
        int i = 0, j = 0;
        while (i < v1.length() && j < v2.length()) {
            int k = nextDot(v1, i), l = nextDot(v2, j);
            int num1 = stoi(v1.substr(i, k - i)), num2 = stoi(v2.substr(j, l - j));
            if (num1 == num2) {

            } else if (num1 > num2) {
                return 1;
            } else {
                return -1;
            }
            i = k + 1, j = l + 1;
        }
        string trail;
        int possibleRes;
        if (i < v1.length()) {
            trail = v1.substr(i, v1.length() - i);
            possibleRes = 1;
        }
        if (j < v2.length()) {
            trail = v2.substr(j, v2.length() - j);
            possibleRes = -1;
        }
        for (const auto &c: trail) {
            if (c >= '1' && c <= '9') {
                return possibleRes;
            }
        }
        return 0;
    }

    int nextDot(string &s, int i) {
        for (; i < s.length(); i++) {
            if (s[i] == '.') {
                break;
            }
        }
        return i;
    }
};
