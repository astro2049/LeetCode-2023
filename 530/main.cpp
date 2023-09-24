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
    vector<int> nums;

    int getMinimumDifference(TreeNode *root) {
        traverse(root);
        int minDiff = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            minDiff = min(minDiff, nums[i] - nums[i - 1]);
        }
        return minDiff;
    }

    void traverse(TreeNode *n) {
        if (!n) {
            return;
        }
        if (n->left) {
            traverse(n->left);
        }
        nums.push_back(n->val);
        if (n->right) {
            traverse(n->right);
        }
    }
};
