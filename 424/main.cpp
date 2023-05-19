#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int characterReplacement(string s, int k) {
        int h[26] = {0};
        int maxFreq;
        int maxLen = 0;
        h[s[0] - 'A']++;
        maxFreq = 1;
        for (int i = 0, j = 0;;) {
            int len = j - i + 1;
            if (len - maxFreq <= k) {
                maxLen = max(maxLen, len);
                j++;
                if (j == s.length()) {
                    break;
                }
                h[s[j] - 'A']++;
                maxFreq = max(maxFreq, h[s[j] - 'A']);
            } else {
                h[s[i] - 'A']--;
                i++;
            }
        }
        return maxLen;
    }
};

class Solution1 {
public:
    vector<int> m = vector<int>(26);

    int characterReplacement(string s, int k) {
        int maxL = 1;
        m[s[0] - 'A']++;
        for (int l = 0, r = 0;;) {
            int len = r - l + 1;
            if (len - maxF() <= k) {
                maxL = max(len, maxL);
                r++;
                if (r == s.length()) {
                    break;
                }
                m[s[r] - 'A']++;
            } else {
                m[s[l] - 'A']--;
                l++;
            }
        }
        return maxL;
    }

    int maxF() {
        int maxFreq = 0;
        for (int i = 0; i < 26; i++) {
            maxFreq = max(m[i], maxFreq);
        }
        return maxFreq;
    }
};
