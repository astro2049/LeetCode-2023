#include <iostream>
#include "vector"
#include "unordered_map"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class TrieNode {
public:
    unordered_map<char, TrieNode *> children;
    bool endOfWord = false;
};

class Trie {
public:
    TrieNode *root = new TrieNode();

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
};

class Solution {
public:
    int m, n;
    vector<vector<char>> board;
    vector<vector<bool>> visited;
    string w;
    vector<string> v;

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        m = board.size(), n = board[0].size();
        this->board = board;
        visited = vector<vector<bool>>(m, vector<bool>(n));
        Trie trie = *new Trie();
        for (auto word: words) {
            trie.insert(word);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j, trie.root);
            }
        }
        return v;
    }

    void dfs(int r, int c, TrieNode *tn) {
        if (r < 0 || r == m || c < 0 || c == n || tn->children.find(board[r][c]) == tn->children.end() ||
            visited[r][c]) {
            return;
        }
        tn = tn->children[board[r][c]];
        w += board[r][c];
        if (tn->endOfWord) {
            v.push_back(w);
            tn->endOfWord = false;
        }
        visited[r][c] = true;
        dfs(r - 1, c, tn);
        dfs(r + 1, c, tn);
        dfs(r, c - 1, tn);
        dfs(r, c + 1, tn);
        w.pop_back();
        visited[r][c] = false;
    }
};
