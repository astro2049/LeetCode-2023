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
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *prev = dummy;
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }
        ListNode *c = prev->next;
        for (int i = 0; i < right - left; i++) {
            ListNode *n = c->next;
            c->next = n->next;
            n->next = prev->next;
            prev->next = n;
        }
        return dummy->next;
    }
};

class Solution1 {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }
        ListNode *start = prev->next;
        ListNode *end = start;
        for (int i = left; i < right; i++) {
            end = end->next;
        }
        ListNode *afterNext = end->next;

        ListNode *p = afterNext, *c = start;
        while (c != afterNext) {
            ListNode *n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        prev->next = p;

        return dummy->next;
    }
};
