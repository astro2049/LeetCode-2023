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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *dummy = new ListNode(), *p = dummy;
        ListNode *l1 = list1, *l2 = list2;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1) {
            p->next = l1;
        }
        if (l2) {
            p->next = l2;
        }
        return dummy->next;
    }
};

class Solution1 {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *d = new ListNode(), *j = list1, *k = list2;
        ListNode *r = d;
        while (j && k) {
            if (j->val < k->val) {
                d->next = j;
                j = j->next;
            } else {
                d->next = k;
                k = k->next;
            }
            d = d->next;
        }
        if (j) {
            d->next = j;
        }
        if (k) {
            d->next = k;
        }
        return r->next;
    }
};
