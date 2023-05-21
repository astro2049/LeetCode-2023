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
    int maxD = 0;

    int maxDepth(TreeNode *root) {
        traverse(root, 0);
        return maxD;
    }

    void traverse(TreeNode *n, int d) {
        if (!n) {
            maxD = max(maxD, d);
            return;
        }
        d++;
        traverse(n->left, d);
        traverse(n->right, d);
    }
};


class Solution1 {
public:
    int maxD = 0;

    int maxDepth(TreeNode *root) {
        preorder(root, 0);
        return maxD;
    }

    void preorder(TreeNode *n, int depth) {
        if (n == nullptr) {
            maxD = max(maxD, depth);
            return;
        }
        depth++;
        preorder(n->left, depth);
        preorder(n->right, depth);
    }
};
