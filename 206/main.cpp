#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (!head) {
            return head;
        }
        ListNode *p = nullptr, *c = head;
        while (c) {
            ListNode *n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }
};
