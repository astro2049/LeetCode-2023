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
    vector<int> rightSideView(TreeNode *root) {
        if (!root) {
            return {};
        }
        vector<int> vals;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int count = q.size();
            int rVal;
            for (int i = 0; i < count; i++) {
                TreeNode *c = q.front();
                q.pop();
                rVal = c->val;
                if (c->left) {
                    q.push(c->left);
                }
                if (c->right) {
                    q.push(c->right);
                }
            }
            vals.push_back(rVal);
        }
        return vals;
    }
};
