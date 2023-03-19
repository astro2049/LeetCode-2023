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
    bool isValidBST(TreeNode *root) {
        return validate(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }

    bool validate(TreeNode *n, long long min, long long max) {
        if (n == nullptr) {
            return true;
        }
        if (min < n->val && n->val < max) {
            return validate(n->left, min, n->val) && validate(n->right, n->val, max);
        } else {
            return false;
        }
    }
};
