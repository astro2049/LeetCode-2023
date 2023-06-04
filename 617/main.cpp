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
    TreeNode *mergeTrees(TreeNode *n1, TreeNode *n2) {
        if (!n1 && !n2) {
            return nullptr;
        } else if (n1 && n2) {
            n1->val += n2->val;
            n1->left = mergeTrees(n1->left, n2->left);
            n1->right = mergeTrees(n1->right, n2->right);
            return n1;
        } else if (n1) {
            return n1;
        } else {
            return n2;
        }
    }
};

class Solution1 {
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        return merge(root1, root2);
    }

    TreeNode *merge(TreeNode *j, TreeNode *k) {
        if (j && k) {
            j->val += k->val;
            j->left = merge(j->left, k->left);
            j->right = merge(j->right, k->right);
            return j;
        } else if (!j && !k) {
            return nullptr;
        } else if (j) {
            return j;
        } else {
            return k;
        }
    }
};

