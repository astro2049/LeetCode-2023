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
    int m, n;
    vector<vector<bool>> visited;

    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
        m = maze.size(), n = maze[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n));
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        int dis = 0;
        while (!q.empty()) {
            int amount = q.size();
            for (int i = 0; i < amount; i++) {
                auto coord = q.front();
                q.pop();
                int x = coord.first, y = coord.second;
                if (x < 0 || x >= m || y < 0 || y >= n) {
                    if (dis - 1 != 0) {
                        return dis - 1;
                    }
                } else {
                    if (visited[x][y]) {
                        continue;
                    }
                    visited[x][y] = true;
                    if (maze[x][y] == '+') {
                        continue;
                    } else {
                        q.push({x + 1, y});
                        q.push({x - 1, y});
                        q.push({x, y + 1});
                        q.push({x, y - 1});
                    }
                }
            }
            dis++;
        }
        return -1;
    }
};
