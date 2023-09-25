#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> combos;
    vector<int> combo;
    int n, k;

    vector<vector<int>> combine(int n, int k) {
        this->n = n, this->k = k;
        traverse(1, 1);
        return combos;
    }

    void traverse(int x, int i) {
        if (i == k + 1) {
            combos.push_back(combo);
            return;
        } else if (x > n) {
            return;
        }
        combo.push_back(x);
        traverse(x + 1, i + 1);
        combo.pop_back();
        traverse(x + 1, i);
    }
};

class Solution1 {
public:
    vector<vector<int>> combos;
    vector<int> combo;
    int n, k;

    vector<vector<int>> combine(int n, int k) {
        this->n = n, this->k = k;
        traverse(1, 1);
        return combos;
    }

    void traverse(int x, int i) {
        if (x + (k - i) > n) {
            return;
        } else if (i == k + 1) {
            combos.push_back(combo);
            return;
        }
        combo.push_back(x);
        traverse(x + 1, i + 1);
        combo.pop_back();
        traverse(x + 1, i);
    }
};
