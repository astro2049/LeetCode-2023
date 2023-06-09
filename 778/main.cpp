#include <iostream>
#include "vector"
#include "queue"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int swimInWater(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<vector<bool>> visit(n, vector<bool>(n));
        auto greater = [](const auto &a, const auto &b) {
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(greater)> minQ(greater);
        minQ.push({grid[0][0], 0, 0});
        vector<vector<int>> direcs = {{1,  0},
                                      {-1, 0},
                                      {0,  1},
                                      {0,  -1}};
        while (!minQ.empty()) {
            auto v = minQ.top();
            minQ.pop();
            int h = v[0], r = v[1], c = v[2];
            if (visit[r][c]) {
                continue;
            } else if (r == n - 1 && c == n - 1) {
                return h;
            }
            visit[r][c] = true;
            for (auto d: direcs) {
                int dr = r + d[0], dc = c + d[1];
                if (dr < 0 || dr >= n || dc < 0 || dc >= n) {
                    continue;
                }
                minQ.push({max(h, grid[dr][dc]), dr, dc});
            }
        }
        return -1;
    }
};
