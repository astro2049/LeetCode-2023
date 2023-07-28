#include <iostream>
#include "unordered_set"
#include "vector"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<char> vowels;
        vector<int> vowelPoss;
        for (int i = 0; i < s.length(); i++) {
            if (set.find(s[i]) != set.end()) {
                vowels.emplace_back(s[i]);
                vowelPoss.emplace_back(i);
            }
        }
        string o = s;
        sort(vowels.begin(), vowels.end());
        for (int i = 0; i < vowelPoss.size(); i++) {
            int pos = vowelPoss[i];
            o[pos] = vowels[i];
        }
        return o;
    }
};
