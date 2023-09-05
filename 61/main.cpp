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
    ListNode *rotateRight(ListNode *head, int k) {
        int count = 0;
        ListNode *n = head;
        while (n) {
            count++;
            n = n->next;
        }
        k = count != 0 ? k % count : 0;
        if (k == 0) {
            return head;
        } else {
            n = head;
            for (int i = 0; i < count - 1 - k; i++) {
                n = n->next;
            }
            ListNode *newHead = n->next;
            n->next = nullptr;
            for (n = newHead; n->next != nullptr; n = n->next) {

            }
            n->next = head;
            return newHead;
        }
    }
};

class Solution1 {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        int count = 0;
        ListNode *n = head;
        while (n) {
            count++;
            n = n->next;
        }
        k = count != 0 ? k % count : 0;
        if (k == 0) {
            return head;
        } else {
            ListNode *s = head, *f = head;
            for (int i = 0; i < k; i++) {
                f = f->next;
            }
            while (f->next) {
                s = s->next;
                f = f->next;
            }
            ListNode *newHead = s->next;
            s->next = nullptr;
            f->next = head;
            return newHead;
        }
    }
};
