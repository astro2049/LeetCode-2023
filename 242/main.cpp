#include <iostream>
#include "string"
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mapS(26), mapT(26);
        for (char c: s) {
            mapS[c - 'a']++;
        }
        for (char c: t) {
            mapT[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (mapS[i] != mapT[i]) {
                return false;
            }
        }
        return true;
    }
};
