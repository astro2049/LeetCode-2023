#include <iostream>
#include "vector"

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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        while (lists.size() != 1) {
            vector<ListNode *> merged;
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode *l1 = lists[i];
                ListNode *l2 = i + 1 < lists.size() ? lists[i + 1] : nullptr;
                merged.push_back(mergeTwoLists(l1, l2));
            }
            lists = merged;
        }
        return lists[0];
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(), *x = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                x->next = l1;
                l1 = l1->next;
            } else {
                x->next = l2;
                l2 = l2->next;
            }
            x = x->next;
        }
        if (l1) {
            x->next = l1;
        }
        if (l2) {
            x->next = l2;
        }
        return dummy->next;
    }
};
