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
    int val;

    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        this->val = val;
        traverse(root);
        return root;
    }

    void traverse(TreeNode *n) {
        if (val < n->val) {
            if (n->left == nullptr) {
                n->left = new TreeNode(val);
            } else {
                traverse(n->left);
            }
        } else {
            if (n->right == nullptr) {
                n->right = new TreeNode(val);
            } else {
                traverse(n->right);
            }
        }
    }
};
