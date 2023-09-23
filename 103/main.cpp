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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> levels;
        queue<TreeNode *> q;
        q.push(root);
        bool fromLeft = true;
        while (!q.empty()) {
            int size = q.size();
            deque<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode *n = q.front();
                q.pop();
                fromLeft ? level.push_back(n->val) : level.push_front(n->val);
                if (n->left) {
                    q.push(n->left);
                }
                if (n->right) {
                    q.push(n->right);
                }
            }
            fromLeft = !fromLeft;
            levels.emplace_back(level.begin(), level.end());
        }
        return levels;
    }
};
