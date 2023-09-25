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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return construct(nums, 0, nums.size() - 1);
    }

    TreeNode *construct(vector<int> &nums, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        int mid = (l + r) / 2;
        auto *n = new TreeNode(nums[mid]);
        n->left = construct(nums, l, mid - 1);
        n->right = construct(nums, mid + 1, r);
        return n;
    }
};
