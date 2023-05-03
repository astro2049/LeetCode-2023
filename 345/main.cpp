#include <iostream>
#include "string"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        string vowels = "aeiouAEIOU";
        while (i < j) {
            if (vowels.find(s[i]) != -1 && vowels.find(s[j]) != -1) {
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
                i++;
                j--;
            } else if (vowels.find(s[i]) != -1) {
                j--;
            } else if (vowels.find(s[j]) != -1) {
                i++;
            } else {
                i++;
                j--;
            }
        }

        return s;
    }
};
