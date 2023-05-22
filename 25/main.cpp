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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *prev = dummy;
        while (true) {
            ListNode *f = prev;
            for (int i = 0; i < k; i++) {
                f = f->next;
                if (!f) {
                    return dummy->next;
                }
            }
            ListNode *c = prev->next;
            for (int i = 0; i < k - 1; i++) {
                ListNode *n = c->next;
                c->next = n->next;
                n->next = prev->next;
                prev->next = n;
            }
            prev = c;
        }
    }
};
