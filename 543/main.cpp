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
    int diam = 0;

    int diameterOfBinaryTree(TreeNode *root) {
        traverse(root);
        return diam - 1;
    }

    int traverse(TreeNode *n) {
        if (!n) {
            return 0;
        }
        int l = traverse(n->left);
        int r = traverse(n->right);
        diam = max(diam, l + r + 1);
        return max(l, r) + 1;
    }
};
