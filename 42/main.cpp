#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int trap(vector<int> &height) {
        vector<int> ls(height.size()), rs(height.size());
        int l = 0;
        ls[0] = 0;
        for (int i = 1; i < height.size(); i++) {
            l = max(l, height[i - 1]);
            ls[i] = l;
        }
        rs.back() = 0;
        int r = 0;
        for (int i = height.size() - 2; i >= 0; i--) {
            r = max(r, height[i + 1]);
            rs[i] = r;
        }
        int amount = 0;
        for (int i = 0; i < height.size(); i++) {
            int unit = min(ls[i], rs[i]) - height[i];
            if (unit > 0) {
                amount += unit;
            }
        }
        return amount;
    }
};
