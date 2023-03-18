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
    ListNode *removeElements(ListNode *head, int val) {
        if (!head) {
            return nullptr;
        }
        ListNode *d = new ListNode(), *l = d, *r = head;
        d->next = head;
        while (r) {
            if (r->val == val) {
                r = r->next;
            } else {
                l->next = r;
                l = l->next;
                r = r->next;
            }
        }
        l->next = nullptr;
        return d->next;
    }
};
