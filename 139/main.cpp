#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        vector<bool> dp(s.length() + 1);
        dp.back() = true;
        for (int i = s.length() - 1; i >= 0; i--) {
            for (auto word: wordDict) {
                if (s.find(word, i) == i) {
                    dp[i] = dp[i + word.length()];
                    if (dp[i]) {
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};
