#include <iostream>
#include "unordered_map"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> ps;
        unordered_map<string, char> sp;
        string x;
        int k = 0;
        for (int i = 0, j = 0; i < s.length() && j < s.length();) {
            if (j == s.length() - 1 || s[j + 1] == ' ') {
                x = s.substr(i, j - i + 1);
                i = j + 2;
                j = i;
                char a = pattern[k];
                if (ps.find(a) == ps.end() && sp.find(x) == sp.end()) {
                    ps[a] = x;
                    sp[x] = a;
                    k++;
                } else if (ps.find(a) == ps.end() || sp.find(x) == sp.end()) {
                    return false;
                } else {
                    if (ps[a] == x && sp[x] == a) {
                        k++;
                        continue;
                    } else {
                        return false;
                    }
                }
            } else {
                j++;
            }
        }
        return k == pattern.length();
    }
};
