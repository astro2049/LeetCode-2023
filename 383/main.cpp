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
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> letters;
        for (char c: magazine) {
            letters[c]++;
        }
        for (char c: ransomNote) {
            letters[c]--;
            if (letters[c] < 0) {
                return false;
            }
        }
        return true;
    }
};
