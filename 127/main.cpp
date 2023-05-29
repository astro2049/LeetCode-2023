#include <iostream>
#include "vector"
#include "queue"
#include "unordered_map"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &words) {
        int beginI;
        auto pos = find(words.begin(), words.end(), beginWord);
        if (pos == words.end()) {
            words.push_back(beginWord);
            beginI = words.size() - 1;
        } else {
            beginI = pos - words.begin();
        }
        int len = beginWord.length();
        unordered_map<string, vector<int>> m;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < len; j++) {
                string x = words[i];
                x[j] = '*';
                m[x].push_back(i);
            }
        }
        queue<int> q;
        vector<bool> visit(words.size());
        q.push(beginI);
        visit[beginI] = true;
        int trans = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int c = q.front();
                if (words[c] == endWord) {
                    return trans;
                }
                q.pop();
                for (int j = 0; j < len; j++) {
                    string x = words[c];
                    x[j] = '*';
                    for (auto neighbor: m[x]) {
                        if (!visit[neighbor]) {
                            visit[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
            trans++;
        }
        return 0;
    }
};
