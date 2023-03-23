#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *s = head, *f = head;
        while (f) {
            s = s->next;
            f = f->next;
            if (!f) {
                return nullptr;
            } else {
                f = f->next;
            }
            if (s == f) {
                break;
            }
        }
        if (!f) {
            return nullptr;
        }
        ListNode *k = head;
        while (k != s) {
            k = k->next;
            s = s->next;
        }
        return k;
    }
};
