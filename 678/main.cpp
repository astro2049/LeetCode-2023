#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0, leftMax = 0;
        for (auto c: s) {
            if (c == '(') {
                leftMin++, leftMax++;
            } else if (c == '*') {
                leftMin--, leftMax++;
            } else {
                leftMin--, leftMax--;
            }
            if (leftMax < 0) {
                return false;
            }
            if (leftMin < 0) {
                leftMin = 0;
            }
        }
        return leftMin == 0;
    }
};

class Solution1 {
public:
    string s;
    vector<vector<int>> dp;

    bool checkValidString(string s) {
        this->s = s;
        dp.resize(s.length(), vector<int>(s.length(), -1));
        return dfs(0, 0);
    }

    bool dfs(int i, int count) {
        if (i == s.length()) {
            return count == 0;
        } else if (dp[i][count] != -1) {
            return dp[i][count];
        }
        char c = s[i];
        if (c == '(') {
            dp[i][count] = dfs(i + 1, count + 1);
            return dp[i][count];
        } else if (c == '*') {
            dp[i][count] = dfs(i + 1, count + 1) || dfs(i + 1, count) || (count == 0 ? false : dfs(i + 1, count - 1));
            return dp[i][count];
        } else {
            dp[i][count] = count == 0 ? false : dfs(i + 1, count - 1);
            return dp[i][count];
        }
    }
};

class Solution2 { // why is this so fast??
public:
    string s;
    int count;

    bool checkValidString(string s) {
        this->s = s;
        return dfs(0);
    }

    bool dfs(int i) {
        if (i == s.length()) {
            return count == 0;
        }
        char c = s[i];
        if (c == '(') {
            count++;
            bool choice = dfs(i + 1);
            count--;
            return choice;
        } else if (c == '*') {
            count++;
            bool choice1 = dfs(i + 1);
            count--;
            bool choice2 = dfs(i + 1);
            s[i] = ')';
            bool choice3 = dfs(i);
            return choice1 || choice2 || choice3;
        } else {
            if (count == 0) {
                return false;
            } else {
                count--;
                bool choice = dfs(i + 1);
                count++;
                return choice;
            }
        }
    }
};
