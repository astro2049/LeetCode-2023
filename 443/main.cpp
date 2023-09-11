#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int compress(vector<char> &chars) {
        int i = 0, j = 0;
        int count = 0;
        for (; j < chars.size(); j++) {
            count++;
            if (j == chars.size() - 1 || chars[j] != chars[j + 1]) {
                chars[i] = chars[j];
                i++;
                if (count == 1) {

                } else {
                    string x = to_string(count);
                    for (const auto &c: x) {
                        chars[i] = c;
                        i++;
                    }
                }
                count = 0;
            }
        }
        return i;
    }
};
