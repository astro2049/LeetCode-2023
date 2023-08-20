#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string s1, s2;

    bool canMakeSubsequence(string str1, string str2) {
        s1 = str1, s2 = str2;
        return match(0, 0);
    }

    bool match(int i, int j) {
        if (j == s2.length()) {
            return true;
        } else if (i == s1.length()) {
            return false;
        } else {
            char n = s1[i] == 'z' ? 'a' : s1[i]++;
            if (s1[i] == s2[j] || n == s2[j]) {
                i++;
                j++;
            } else {
                i++;
            }
            return match(i, j);
        }
    }
};
