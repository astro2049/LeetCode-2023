#include <iostream>
#include "vector"
#include "unordered_set"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxLen = 0, len = 0;
        for (int n: s) {
            if (s.find(n - 1) == s.end()) {
                len++;
                for (int c = n + 1;;) {
                    if (s.find(c) != s.end()) {
                        len++;
                        c++;
                    } else {
                        break;
                    }
                }
                maxLen = max(maxLen, len);
                len = 0;
            } else {
                continue;
            }
        }
        return maxLen;
    }
};
