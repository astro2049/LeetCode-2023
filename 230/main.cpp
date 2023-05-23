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
    vector<int> v;

    int kthSmallest(TreeNode *root, int k) {
        traverse(root);
        return v[k - 1];
    }

    void traverse(TreeNode *n) {
        if (!n) {
            return;
        }
        traverse(n->left);
        v.push_back(n->val);
        traverse(n->right);
    }
};
