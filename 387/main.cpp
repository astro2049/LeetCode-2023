#include <iostream>
#include "string"
#include "unordered_map"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for (char c: s) {
            map[c]++;
        }
        for (char c: s) {
            if (map[c] == 1) {
                return s.find(c);
            }
        }
        return -1;
    }
};
