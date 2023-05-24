#include <iostream>
#include "unordered_map"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

struct TrieNode {
    unordered_map<char, TrieNode *> children;
    bool endOfWord = false;
};

class WordDictionary {
public:
    TrieNode *root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode *n = root;
        for (char c: word) {
            if (n->children.find(c) == n->children.end()) {
                n->children[c] = new TrieNode();
            }
            n = n->children[c];
        }
        n->endOfWord = true;
    }

    bool search(string word) {
        return dfs(root, 0, word);
    }

    bool dfs(TrieNode *n, int iStart, string word) {
        for (int i = iStart; i < word.length(); i++) {
            char c = word[i];
            if (c == '.') {
                for (auto p: n->children) {
                    if (dfs(p.second, i + 1, word)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (n->children.find(c) == n->children.end()) {
                    return false;
                }
                n = n->children[c];
            }
        }
        return n->endOfWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
