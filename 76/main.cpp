#include <iostream>


using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) {
            return "";
        }
        int h1[52] = {0}, h2[52] = {0};
        for (int i = 0; i < t.length(); i++) {
            h1[hash(s[i])]++;
            h2[hash(t[i])]++;
        }
        int qualifies = 0;
        for (int i = 0; i < 52; i++) {
            if (h1[i] >= h2[i]) {
                qualifies++;
            }
        }
        int minI = -1, minLen = INT_MAX;
        for (int i = 0, j = t.length();;) {
            if (qualifies == 52) {
                if (j - i < minLen) {
                    minI = i;
                    minLen = j - i;
                }
                h1[hash(s[i])]--;
                if (h1[hash(s[i])] == h2[hash(s[i])] - 1) {
                    qualifies--;
                }
                i++;
            } else {
                if (j == s.length()) {
                    break;
                }
                h1[hash(s[j])]++;
                if (h1[hash(s[j])] == h2[hash(s[j])]) {
                    qualifies++;
                }
                j++;
            }
        }
        return minI == -1 ? "" : s.substr(minI, minLen);
    }

    int hash(char c) {
        if (c >= 'a' && c <= 'z') {
            return c - 'a';
        } else {
            return c - 'A' + 26;
        }
    }
};
