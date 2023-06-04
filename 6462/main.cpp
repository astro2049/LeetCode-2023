#include <iostream>
#include "unordered_set"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> st;
        for (auto c: s) {
            st.insert(c);
        }
        return st.size();
    }
};
