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
