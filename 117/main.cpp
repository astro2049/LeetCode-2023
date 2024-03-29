#include <iostream>
#include "queue"

using namespace std;

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
        if (!root) {
            return root;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            Node *prev = nullptr;
            for (int i = 0; i < size; i++) {
                Node *cur = q.front();
                q.pop();
                cur->next = prev;
                if (cur->right) {
                    q.push(cur->right);
                }
                if (cur->left) {
                    q.push(cur->left);
                }
                prev = cur;
            }
        }
        return root;
    }
};
