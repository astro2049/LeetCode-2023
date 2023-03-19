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

    bool findTarget(TreeNode *root, int k) {
        inorder(root);
        int l = 0, r = v.size() - 1;
        while (l < r) {
            int sum = v[l] + v[r];
            if (sum > k) {
                r--;
            } else if (sum < k) {
                l++;
            } else {
                return true;
            }
        }
        return false;
    }

    void inorder(TreeNode *n) {
        if (n == nullptr) {
            return;
        }
        inorder(n->left);
        v.push_back(n->val);
        inorder(n->right);
    }
};
