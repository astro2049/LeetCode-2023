#include <iostream>
#include "stack"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss, st;
        for (char c: s) {
            if (c == '#') {
                if (ss.empty()) {
                    continue;
                } else {
                    ss.pop();
                }
            } else {
                ss.push(c);
            }
        }
        for (char c: t) {
            if (c == '#') {
                if (st.empty()) {
                    continue;
                } else {
                    st.pop();
                }
            } else {
                st.push(c);
            }
        }
        if (ss.size() != st.size()) {
            return false;
        } else {
            while (!ss.empty() && !st.empty()) {
                char ssC = ss.top(), stC = st.top();
                if (ssC == stC) {
                    ss.pop();
                    st.pop();
                } else {
                    return false;
                }
            }
            return true;
        }
    }
};

class Solution1 {
public:
    bool backspaceCompare(string s, string t) {
        return construct(s) == construct(t);
    }

    string construct(string s) {
        string x;
        for (char c: s) {
            if (c != '#') {
                x.push_back(c);
            } else {
                if (!x.empty()) {
                    x.pop_back();
                }
            }
        }
        return x;
    }
};
