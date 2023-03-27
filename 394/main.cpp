#include <iostream>
#include "stack"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string decodeString(string s) {
        stack<char> sta;
        for (char c: s) {
            if (c != ']') {
                sta.push(c);
            } else {
                string piece;
                while (sta.top() != '[') {
                    piece.push_back(sta.top());
                    sta.pop();
                }
                sta.pop();
                reverse(piece.begin(), piece.end());
                string n;
                while (!sta.empty() && sta.top() >= '0' && sta.top() <= '9') {
                    n.push_back(sta.top());
                    sta.pop();
                }
                reverse(n.begin(), n.end());
                int nn = stoi(n);
                for (int j = 0; j < nn; j++) {
                    for (char k: piece) {
                        sta.push(k);
                    }
                }
            }
        }
        string x;
        while (!sta.empty()) {
            x.push_back(sta.top());
            sta.pop();
        }
        reverse(x.begin(), x.end());
        return x;
    }
};
