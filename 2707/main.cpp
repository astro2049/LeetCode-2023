#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int minExtraChar(string s, vector<string> &dictionary) {
        vector<int> dp(s.length() + 1);
        for (int i = s.length() - 1; i >= 0; i--) {
            dp[i] = 1 + dp[i + 1];
            for (const auto &w: dictionary) {
                if (s.find(w, i) == i) {
                    dp[i] = min(dp[i], dp[i + w.length()]);
                }
            }
        }
        return dp[0];
    }
};