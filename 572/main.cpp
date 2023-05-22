#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool yes = false;
    TreeNode *sr;

    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        sr = subRoot;
        traverse(root);
        return yes;
    }

    void traverse(TreeNode *n) {
        if (!n) {
            return;
        }
        if (n->val == sr->val) {
            if (isSameTree(n, sr)) {
                yes = true;
                return;
            }
        }
        traverse(n->left);
        traverse(n->right);
    }

    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) {
            return true;
        } else if (!p || !q) {
            return false;
        } else {
            return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};
