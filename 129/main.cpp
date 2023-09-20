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
    int sum = 0;
    string num;

    int sumNumbers(TreeNode *root) {
        traverse(root);
        return sum;
    }

    void traverse(TreeNode *n) {
        if (!n->left && !n->right) {
            num += n->val + '0';
            sum += stoi(num);
            num.pop_back();
            return;
        }
        num += n->val + '0';
        if (n->left) {
            traverse(n->left);
        }
        if (n->right) {
            traverse(n->right);
        }
        num.pop_back();
    }
};
