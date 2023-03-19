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
    int targetSum;

    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) {
            return false;
        }
        this->targetSum = targetSum;
        return traverse(root, 0);
    }

    bool traverse(TreeNode *n, int sum) {
        if (!n) {
            return false;
        }
        sum += n->val;
        if (!n->left && !n->right) {
            return sum == this->targetSum;
        }
        return traverse(n->left, sum) || traverse(n->right, sum);
    }
};

class SolutionS {
public:
    int targetSum;

    bool hasPathSum(TreeNode *r, int targetSum) {
        if (!r) {
            return false;
        }
        targetSum -= r->val;
        if (!r->left && !r->right) {
            return targetSum == 0;
        }
        return hasPathSum(r->left, targetSum) || hasPathSum(r->right, targetSum);
    }
};
