#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<string> pars;

    vector<string> generateParenthesis(int n) {
        makePars(0, 0, "", n);
        return pars;
    }

    void makePars(int open, int close, string s, int n) {
        if (open == n && close == n) {
            pars.push_back(s);
        } else {
            if (open < n) {
                makePars(open + 1, close, s + "(", n);
            }
            if (close < open) {
                makePars(open, close + 1, s + ")", n);
            }
        }
    }
};
