#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string s;
    int maxLen = 1;

    int longestSemiRepetitiveSubstring(string s) {
        this->s = s;
        dfs(0, 1, false);
        return maxLen;
    }

    void dfs(int l, int r, bool dup) {
        if (r == s.length()) {
            return;
        }
        if (s[r - 1] != s[r]) {
            maxLen = max(maxLen, r - l + 1);
            dfs(l, r + 1, dup);
        } else {
            if (!dup) {
                maxLen = max(maxLen, r - l + 1);
                dfs(l, r + 1, true);
            } else {
                dfs(r - 1, r + 1, true);
            }
            dfs(r, r + 1, false);
        }
    }
};
