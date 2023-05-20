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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(), *c = dummy;
        bool plus1 = false;
        while (l1 || l2) {
            ListNode *s = new ListNode();
            int a = l1 ? l1->val : 0, b = l2 ? l2->val : 0;
            s->val = a + b + plus1;
            if (s->val >= 10) {
                s->val -= 10;
                plus1 = true;
            } else {
                plus1 = false;
            }
            c->next = s;
            c = c->next;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (plus1) {
            c->next = new ListNode(1);
        }
        return dummy->next;
    }
};
