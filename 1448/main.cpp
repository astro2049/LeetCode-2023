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
    int count = 0;

    int goodNodes(TreeNode *root) {
        traverse(root, root->val);
        return count;
    }

    void traverse(TreeNode *n, int max) {
        if (!n) {
            return;
        }
        if (max <= n->val) {
            count++;
            max = n->val;
        }
        traverse(n->left, max);
        traverse(n->right, max);
    }
};
