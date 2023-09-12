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
    void flatten(TreeNode *root) {
        TreeNode *n = root;
        while (n) {
            if (!n->left) {
                n = n->right;
            } else {
                TreeNode *pre = n->left;
                while (pre->right) {
                    pre = pre->right;
                }
                pre->right = n->right;
                n->right = n->left;
                n->left = nullptr;
                n = n->right;
            }
        }
    }
};
