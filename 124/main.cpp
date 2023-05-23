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
    int maxSum = INT_MIN;

    int maxPathSum(TreeNode *root) {
        traverse(root);
        return maxSum;
    }

    int traverse(TreeNode *n) {
        if (!n) {
            return 0;
        }
        int left = traverse(n->left);
        int right = traverse(n->right);
        maxSum = max(maxSum, left + n->val + right);
        return max(0, max(left, right) + n->val);
    }
};
