#include <iostream>

using namespace std;

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
    void reorderList(ListNode *head) {
        ListNode *s = head, *f = head;
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
        }
        ListNode *prev = nullptr, *c = s;
        while (c) {
            ListNode *next = c->next;
            c->next = prev;
            prev = c;
            c = next;
        }
        ListNode *l1 = head, *l2 = prev;
        while (l2->next) {
            ListNode *l1next = l1->next, *l2next = l2->next;
            l1->next = l2;
            l2->next = l1next;
            l1 = l1next;
            l2 = l2next;
        }
    }
};
