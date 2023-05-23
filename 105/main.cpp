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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }
        TreeNode *n = new TreeNode(preorder[0]);
        int mid = 0;
        for (; mid < inorder.size(); mid++) {
            if (preorder[0] == inorder[mid]) {
                break;
            }
        }
        vector<int> lPre{preorder.begin() + 1, preorder.begin() + mid + 1};
        vector<int> lIn{inorder.begin(), inorder.begin() + mid};
        vector<int> rPre{preorder.begin() + mid + 1, preorder.end()};
        vector<int> rIn{inorder.begin() + mid + 1, inorder.end()};
        n->left = buildTree(lPre, lIn);
        n->right = buildTree(rPre, rIn);
        return n;
    }
};
