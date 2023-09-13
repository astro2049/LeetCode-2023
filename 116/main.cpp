#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node *connect(Node *root) {
        Node *n = root, *next = n ? n->left : nullptr;
        while (n && next) {
            n->left->next = n->right;
            if (n->next) {
                n->right->next = n->next->left;
            }
            n = n->next;
            if (!n) {
                n = next;
                next = n->left;
            }
        }
        return root;
    }
};
