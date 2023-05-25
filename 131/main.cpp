#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string s;
    vector<vector<string>> res;
    vector<string> cur;

    vector<vector<string>> partition(string s) {
        this->s = s;
        dfs(0);
        return res;
    }

    void dfs(int i) {
        if (i == s.length()) {
            res.push_back(cur);
            return;
        }
        for (int len = 1; len <= s.length() - i; len++) {
            string x = s.substr(i, len);
            if (isPalin(x)) {
                cur.push_back(x);
                dfs(i + len);
                cur.pop_back();
            }
        }
    }

    bool isPalin(string x) {
        for (int i = 0, j = x.length() - 1; i < j; i++, j--) {
            if (x[i] != x[j]) {
                return false;
            }
        }
        return true;
    }
};
