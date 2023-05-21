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
    bool yes = true;

    bool isBalanced(TreeNode *root) {
        if (!root) {
            return true;
        }
        traverse(root);
        return yes;
    }

    int traverse(TreeNode *n) {
        if (!n) {
            return 0;
        }
        int l = traverse(n->left);
        int r = traverse(n->right);
        if (l < r - 1 || l > r + 1) {
            yes = false;
        }
        return max(l, r) + 1;
    }
};
