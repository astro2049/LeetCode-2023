#include <iostream>
#include "vector"
#include "unordered_map"

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
    vector<int> postorder;
    unordered_map<int, int> inM;

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        this->postorder = postorder;
        for (int i = 0; i < inorder.size(); i++) {
            inM[inorder[i]] = i;
        }
        return build(0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode *build(int is, int ie, int ps, int pe) {
        if (is > ie || ps > pe) {
            return nullptr;
        }
        int val = postorder[pe];
        TreeNode *n = new TreeNode(val);
        n->left = build(is, inM[val] - 1, ps, ps + (inM[val] - 1 - is));
        n->right = build(inM[val] + 1, ie, ps + (inM[val] - is), pe - 1);
        return n;
    }
};
