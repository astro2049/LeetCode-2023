#include <iostream>
#include "vector"
#include "stack"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        string ops = "+-*/";
        for (string t: tokens) {
            if (ops.find(t) != -1) {
                int n2 = s.top();
                s.pop();
                int n1 = s.top();
                s.pop();
                if (t == "+") {
                    s.push(n1 + n2);
                } else if (t == "-") {
                    s.push(n1 - n2);
                } else if (t == "*") {
                    s.push(n1 * n2);
                } else {
                    s.push(n1 / n2);
                }
            } else {
                s.push(stoi(t));
            }
        }
        return s.top();
    }
};
