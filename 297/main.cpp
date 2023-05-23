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

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    string valToS(TreeNode *n) {
        if (!n) {
            return "99999";
        } else {
            string sx = n->val < 0 ? "-" : "0";
            string t = to_string(n->val < 0 ? -n->val : n->val);
            for (int i = 0; i < 4 - t.size(); i++) {
                sx += "0";
            }
            return sx + t; // 5 digits
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string sPre;
        preorder(root, sPre);
        return sPre;
    }

    void preorder(TreeNode *n, string &s) {
        s += valToS(n);
        if (!n) {
            return;
        }
        preorder(n->left, s);
        preorder(n->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        vector<int> pre;
        for (int p = 0; p < data.size(); p += 5) {
            pre.push_back(stoi(data.substr(p, 5)));
        }
        int i = 0;
        return buildTree(pre, i);
    }

    TreeNode *buildTree(vector<int> &pre, int &i) {
        if (pre[i] == 99999) {
            i++;
            return nullptr;
        }
        TreeNode *n = new TreeNode(pre[i]);
        i++;
        n->left = buildTree(pre, i);
        n->right = buildTree(pre, i);
        return n;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
