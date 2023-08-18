#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> para;
        for (int i = 0; i < words.size();) {
            int width = 0;
            int j = i;
            for (; j < words.size(); j++) {
                width += j == i ? 0 : 1;
                width += words[j].length();
                if (width == maxWidth || j == words.size() - 1 ||
                    (j + 1 < words.size() && width + words[j + 1].length() + 1 > maxWidth)) {
                    break;
                }
            }
            string line;
            if (j != words.size() - 1) {
                if (j == i) {
                    line = words[i];
                    string s(maxWidth - line.length(), ' ');
                    line += s;
                } else {
                    width -= j - i;
                    int space = (maxWidth - width) / (j - i);
                    int extraSpaces = maxWidth - width - space * (j - i);
                    string s(space, ' ');
                    int k = i;
                    for (; k < i + extraSpaces; k++) {
                        line += words[k] + s + " ";
                    }
                    for (; k < j; k++) {
                        line += words[k] + s;
                    }
                    line += words[j];
                }
            } else {
                for (int k = i; k <= j - 1; k++) {
                    line += words[k] + " ";
                }
                line += words[j];
                int len = line.length();
                for (int k = 0; k < maxWidth - len; k++) {
                    line += " ";
                }
            }
            para.push_back(line);
            i = j + 1;
        }
        return para;
    }
};
