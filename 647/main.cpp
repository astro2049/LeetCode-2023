#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            int l = i, r = i;
            for (; l >= 0 && r < s.length(); l--, r++) {
                if (s[l] != s[r]) {
                    break;
                }
                count++;
            }
            l = i, r = i + 1;
            for (; l >= 0 && r < s.length(); l--, r++) {
                if (s[l] != s[r]) {
                    break;
                }
                count++;
            }
        }
        return count;
    }
};
