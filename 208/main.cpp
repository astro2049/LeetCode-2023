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

class Trie {
public:
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
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
        TrieNode *n = root;
        for (char c: word) {
            if (n->children.find(c) == n->children.end()) {
                return false;
            }
            n = n->children[c];
        }
        return n->endOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode *n = root;
        for (char c: prefix) {
            if (n->children.find(c) == n->children.end()) {
                return false;
            }
            n = n->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
