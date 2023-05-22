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
        vector<vector<int>> levels;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int count = q.size();
            vector<int> level;
            for (int i = 0; i < count; i++) {
                TreeNode *c = q.front();
                q.pop();
                level.push_back(c->val);
                if (c->left) {
                    q.push(c->left);
                }
                if (c->right) {
                    q.push(c->right);
                }
            }
            levels.push_back(level);
        }
        return levels;
    }
};

class Solution1 {
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
