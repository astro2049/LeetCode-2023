#include <iostream>
#include "string"
#include "unordered_map"
#include "unordered_set"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        unordered_set<char> set;
        for (int i = 0; i < s.length(); i++) {
            char a = s[i], b = t[i];
            if (m.find(a) == m.end() && set.find(b) == set.end()) {
                m[a] = b;
                set.insert(b);
            } else if (m.find(a) != m.end() && m[a] == b) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};

class Solution1 {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        unordered_set<char> set;
        if (s.length() != t.length()) {
            return false;
        }
        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i], c2 = t[i];
            auto x = m.find(c1);
            auto y = set.find(c2);
            if (x == m.end() && y == set.end()) {
                m[c1] = c2;
                set.insert(c2);
            } else {
                if (m[c1] == c2) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
