#include <iostream>
#include "vector"
#include "unordered_map"
#include "unordered_set"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    unordered_map<char, vector<char>> map;
    unordered_set<char> visiting;
    unordered_set<char> visited;
    string res;

    string alienOrder(vector<string> &words) {
        for (const auto &word: words) {
            for (auto c: word) {
                map[c];
            }
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i + 1];
            int minLen = min(w1.length(), w2.length());
            if (w1.length() > w2.length() && w1.substr(0, minLen) == w2) {
                return "";
            }
            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    map[w1[j]].push_back(w2[j]);
                    break;
                }
            }
        }
        for (const auto &p: map) {
            if (!dfs(p.first)) {
                return "";
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(char c) {
        if (visiting.find(c) != visiting.end()) {
            return false;
        } else if (visited.find(c) != visited.end()) {
            return true;
        }
        visiting.insert(c);
        for (auto to: map[c]) {
            if (!dfs(to)) {
                return false;
            }
        }
        visiting.erase(c);
        res += c;
        visited.insert(c);
        return true;
    }
};
