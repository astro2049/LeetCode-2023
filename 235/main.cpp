#include <iostream>

using namespace std;

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        return find(root, p, q);
    }

    TreeNode *find(TreeNode *n, TreeNode *p, TreeNode *q) {
        if (p->val < n->val && q->val < n->val) {
            return find(n->left, p, q);
        } else if (p->val > n->val && q->val > n->val) {
            return find(n->right, p, q);
        } else {
            return n;
        }
    }
};
