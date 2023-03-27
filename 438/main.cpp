#include <iostream>
#include "vector"
#include "unordered_map"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.length() < p.length()) {
            return {};
        }
        unordered_map<char, int> m;
        for (char c: p) {
            m[c]++;
        }
        int count = 0;
        for (int k = 0; k < p.length(); k++) {
            char c = s[k];
            if (m.find(c) != m.end()) {
                m[c]--;
                if (m[c] == 0) {
                    count++;
                }
            }
        }
        vector<int> indices;
        for (int i = 0, j = p.length() - 1;;) {
            if (count == m.size()) {
                indices.push_back(i);
            }
            if (m.find(s[i]) != m.end()) {
                if (m[s[i]] == 0) {
                    count--;
                }
                m[s[i]]++;
            }
            i++;
            j++;
            if (j == s.length()) {
                break;
            }
            if (m.find(s[j]) != m.end()) {
                m[s[j]]--;
                if (m[s[j]] == 0) {
                    count++;
                }
            }
        }
        return indices;
    }
};
