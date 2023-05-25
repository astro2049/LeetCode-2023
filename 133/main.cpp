#include <iostream>
#include "vector"
#include "unordered_map"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node *, Node *> m;

    Node *cloneGraph(Node *node) {
        if (!node) {
            return nullptr;
        }
        dfs(node);
        for (auto pair: m) {
            Node *x = pair.second;
            for (int i = 0; i < x->neighbors.size(); i++) {
                x->neighbors[i] = m[x->neighbors[i]];
            }
        }
        return m[node];
    }

    void dfs(Node *orig) {
        if (m.find(orig) != m.end()) {
            return;
        }
        Node *replica = new Node(orig->val, orig->neighbors);
        m[orig] = replica;
        for (auto neighbor: orig->neighbors) {
            dfs(neighbor);
        }
    }
};
