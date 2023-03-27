#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1) {
            return 1;
        }
        vector<int> l(n, 1);
        vector<int> c(n);
        for (int i = 1; i < m; i++) {
            c[0] = 1;
            for (int j = 1; j < n; j++) {
                c[j] = c[j - 1] + l[j];
            }
            l = c;
        }
        return c.back();
    }
};
