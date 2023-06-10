#include <iostream>
#include "unordered_set"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isFascinating(int n) {
        unordered_set<char> s;
        for (int i = 1; i <= 3; i++) {
            string x = to_string(n * i);
            for (char c: x) {
                if (c == '0' || s.find(c) != s.end()) {
                    return false;
                }
                s.insert(c);
            }
        }
        return s.size() == 9;
    }
};
