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
    unordered_map<char, string> m{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
    vector<string> combos;
    string cur;
    string digits;

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        this->digits = digits;
        dfs(0);
        return combos;
    }

    void dfs(int i) {
        if (i == digits.length()) {
            combos.push_back(cur);
            return;
        }
        char c = digits[i];
        for (char x: m[c]) {
            cur += x;
            dfs(i + 1);
            cur.pop_back();
        }
    }
};
