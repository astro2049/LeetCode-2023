#include <iostream>
#include "vector"
#include "queue"

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
    TreeNode *invertTree(TreeNode *root) {
        traverse(root);
        return root;
    }

    void traverse(TreeNode *n) {
        if (!n) {
            return;
        }
        TreeNode *t = n->left;
        n->left = n->right;
        n->right = t;
        traverse(n->left);
        traverse(n->right);
    }
};
