#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;
    int sColor;
    int color;

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        m = image.size(), n = image[0].size();
        sColor = image[sr][sc];
        this->color = color;
        visited = vector<vector<bool>>(m, vector<bool>(n));
        dfs(image, sr, sc);
        return image;
    }

    void dfs(vector<vector<int>> &image, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c]) {
            return;
        }
        visited[r][c] = true;
        if (image[r][c] != sColor) {
            return;
        }
        image[r][c] = color;
        dfs(image, r - 1, c);
        dfs(image, r + 1, c);
        dfs(image, r, c - 1);
        dfs(image, r, c + 1);
    }
};
