#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string x;
        int i = 0, j = 0;
        while (i < word1.length() && j < word2.length()) {
            x.push_back(word1[i]);
            x.push_back(word2[j]);
            i++;
            j++;
        }
        if (i == word1.length()) {
            x.append(word2.substr(i));
        }
        if (j == word2.length()) {
            x.append(word1.substr(j));
        }
        return x;
    }
};
