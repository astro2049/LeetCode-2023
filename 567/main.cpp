#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        int h1[26] = {0}, h2[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            h1[s1[i] - 'a']++;
            h2[s2[i] - 'a']++;
        }
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (h1[i] == h2[i]) {
                matches++;
            }
        }
        for (int i = 0, j = s1.length(); j < s2.length(); i++, j++) {
            if (matches == 26) {
                return true;
            }
            char a = s2[i], b = s2[j];
            h2[b - 'a']++;
            if (h2[b - 'a'] == h1[b - 'a']) {
                matches++;
            } else if (h2[b - 'a'] == (h1[b - 'a'] + 1)) {
                matches--;
            }
            h2[a - 'a']--;
            if (h2[a - 'a'] == h1[a - 'a']) {
                matches++;
            } else if (h2[a - 'a'] == (h1[a - 'a'] - 1)) {
                matches--;
            }
        }
        return matches == 26;
    }
};
