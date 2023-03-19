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
    TreeNode *searchBST(TreeNode *n, int val) {
        if (!n) {
            return nullptr;
        }
        if (n->val < val) {
            return searchBST(n->right, val);
        } else if (n->val > val) {
            return searchBST(n->left, val);
        } else {
            return n;
        }
    }
};
