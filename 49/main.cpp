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
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> m;
        for (string s: strs) {
            string occur(26, '0');
            for (char c: s) {
                occur[c - 'a']++;
            }
            m[occur].emplace_back(s);
        }
        vector<vector<string>> anas;
        for (auto e: m) {
            anas.emplace_back(e.second);
        }
        return anas;
    }
};
