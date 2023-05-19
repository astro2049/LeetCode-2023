#include <iostream>
#include "unordered_set"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }
        unordered_set<char> x;
        int maxLen = 0;
        for (int i = 0, j = 0; j < s.length();) {
            char c = s[j];
            if (x.find(c) == x.end()) {
                x.insert(c);
                maxLen = max(maxLen, j - i + 1);
                j++;
            } else {
                while (s[i] != c) {
                    x.erase(s[i]);
                    i++;
                }
                x.erase(s[i]);
                i++;
            }
        }
        return maxLen;
    }
};
