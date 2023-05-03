#include <iostream>
#include "string"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string reverseWords(string s) {
        string x, r;
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s[i];
            if (c == ' ') {
                if (x.length() != 0) {
                    reverse(x.begin(), x.end());
                    r += x + " ";
                    x.clear();
                }
            } else {
                x += c;
            }
        }
        if (x.length() != 0) {
            reverse(x.begin(), x.end());
            r += x + " ";
        }
        r.pop_back();
        return r;
    }
};
