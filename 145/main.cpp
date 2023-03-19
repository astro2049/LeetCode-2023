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

    vector<int> postorderTraversal(TreeNode *root) {
        postorder(root);
        return tra;
    }

    void postorder(TreeNode *n) {
        if (n == nullptr) {
            return;
        }
        postorder(n->left);
        postorder(n->right);
        tra.push_back(n->val);
    }
};
