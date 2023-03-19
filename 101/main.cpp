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
    bool isSymmetric(TreeNode *root) {
        return check(root, root);
    }

    bool check(TreeNode *l, TreeNode *r) {
        if (!l && !r) {
            return true;
        } else if (l && r) {
            if (l->val == r->val) {
                return check(l->left, r->right) && check(l->right, r->left);
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};
