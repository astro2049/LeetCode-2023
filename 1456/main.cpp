#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int maxVowels(string s, int k) {
        string vowels = "aeiou";
        int maxCount = 0, count = 0;
        for (int i = 0; i < k; i++) {
            if (vowels.find(s[i]) != -1) {
                count++;
            }
        }
        maxCount = count;
        for (int i = 0, j = k; j < s.length(); i++, j++) {
            if (vowels.find(s[i]) != -1) {
                count--;
            }
            if (vowels.find(s[j]) != -1) {
                count++;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
