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
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> m;
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s[i];
            if (m.find(c) == m.end()) {
                m[c] = i;
            }
        }
        vector<int> res;
        for (int start = 0; start < s.length();) {
            int end = m[s[start]];
            for (int i = start; i <= end; i++) {
                char c = s[i];
                if (m[c] <= end) {
                    continue;
                } else {
                    end = m[c];
                }
            }
            res.push_back(end - start + 1);
            start = end + 1;
        }
        return res;
    }
};
