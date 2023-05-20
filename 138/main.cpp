#include <iostream>
#include "unordered_map"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

// Definition for a Node.
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        unordered_map<Node *, Node *> m;
        Node *n = head;
        Node *dummy = new Node(0), *dc = dummy;
        while (n) {
            Node *c = new Node(n->val);
            m[n] = c;
            dc->next = c;
            n = n->next;
            dc = dc->next;
        }
        n = head, dc = dummy->next;
        while (n) {
            dc->random = m[n->random];
            n = n->next;
            dc = dc->next;
        }
        return dummy->next;
    }
};
