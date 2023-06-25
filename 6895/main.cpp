#include <iostream>
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int x, y, z;
    int maxLen = 0;

    int longestString(int x, int y, int z) {
        this->x = x, this->y = y, this->z = z;
        dfs(0, 'x');
        dfs(0, 'y');
        dfs(0, 'z');
        return maxLen;
    }

    void dfs(int len, char choice) {
        if (choice == 'x') {
            if (x == 0) {
                return;
            } else {
                x--;
                len += 2;
                maxLen = max(maxLen, len);
                dfs(len, 'y');
                x++;
            }
        } else if (choice == 'y') {
            if (y == 0) {
                return;
            } else {
                y--;
                len += 2;
                maxLen = max(maxLen, len);
                if (z == 0) {
                    dfs(len, 'x');
                } else {
                    dfs(len, 'z');
                }
                y++;
            }
        } else {
            if (z == 0) {
                return;
            } else {
                z--;
                len += 2;
                maxLen = max(maxLen, len);
                if (z == 0) {
                    dfs(len, 'x');
                } else {
                    dfs(len, 'z');
                }
                z++;
            }
        }
    }
};
