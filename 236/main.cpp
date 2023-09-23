#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *n, TreeNode *p, TreeNode *q) {
        if (!n || n == p || n == q) {
            return n;
        }
        TreeNode *l = lowestCommonAncestor(n->left, p, q);
        TreeNode *r = lowestCommonAncestor(n->right, p, q);
        if (l && r) {
            return n;
        } else if (l) {
            return l;
        } else if (r) {
            return r;
        } else {
            return nullptr;
        }
    }
};
