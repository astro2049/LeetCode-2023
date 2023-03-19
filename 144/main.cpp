#include <iostream>
#include "vector"

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
    vector<int> tra;

    vector<int> preorderTraversal(TreeNode *root) {
        preorder(root);
        return tra;
    }

    void preorder(TreeNode *n) {
        if (n == nullptr) {
            return;
        }
        tra.push_back(n->val);
        preorder(n->left);
        preorder(n->right);
    }
};
