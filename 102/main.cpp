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
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> a;
        queue<TreeNode *> level;
        level.push(root);
        while (!level.empty()) {
            int count = level.size();
            vector<int> vals;
            for (int i = 0; i < count; i++) {
                TreeNode *n = level.front();
                level.pop();
                if (n) {
                    vals.push_back(n->val);
                    if (n->left) {
                        level.push(n->left);
                    }
                    if (n->right) {
                        level.push(n->right);
                    }
                }
            }
            a.push_back(vals);
        }
        return a;
    }
};
