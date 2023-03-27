#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
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
