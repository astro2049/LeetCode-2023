#include <iostream>
#include "string"
#include "stack"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else {
                if (stk.empty()) {
                    return false;
                }
                if (c == ')') {
                    if (stk.top() == '(') {
                        stk.pop();
                    } else {
                        return false;
                    }
                } else if (c == ']') {
                    if (stk.top() == '[') {
                        stk.pop();
                    } else {
                        return false;
                    }
                } else {
                    if (stk.top() == '{') {
                        stk.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        return stk.empty();
    }
};
