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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *f = dummy;
        for (int i = 0; i < n; i++) {
            f = f->next;
        }
        ListNode *s = dummy;
        while (f && f->next) {
            s = s->next;
            f = f->next;
        }
        s->next = s->next->next;
        return dummy->next;
    }
};
