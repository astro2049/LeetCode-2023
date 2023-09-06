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
    ListNode *partition(ListNode *head, int x) {
        ListNode *leftH = new ListNode(), *rightH = new ListNode();
        ListNode *i = leftH, *j = rightH;
        for (ListNode *n = head; n; n = n->next) {
            if (n->val < x) {
                i->next = n;
                i = i->next;
            } else {
                j->next = n;
                j = j->next;
            }
        }
        j->next = nullptr;
        i->next = rightH->next;
        return leftH->next;
    }
};
