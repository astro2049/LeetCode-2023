#include <iostream>
#include "vector"
#include "unordered_map"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string> &words) {
        unordered_map<string, int> m;
        int count = 0;
        for (const auto &w: words) {
            string x = w;
            reverse(x.begin(), x.end());
            if (m.find(x) == m.end()) {
                m[w]++;
            } else {
                m[x]--;
                count++;
                if (m[x] == 0) {
                    m.erase(x);
                }
            }
        }
        return count;
    }
};
