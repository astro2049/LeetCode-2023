#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int> v;

    vector<int> preorder(Node *root) {
        traverse(root);
        return v;
    }

    void traverse(Node *n) {
        if (!n) {
            return;
        }
        v.push_back(n->val);
        for (Node *x: n->children) {
            traverse(x);
        }
    }
};
