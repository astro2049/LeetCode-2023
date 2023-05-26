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
    void wallsAndGates(vector<vector<int>> &rooms) {
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        vector<vector<int>> directions = {{-1, 0},
                                          {1,  0},
                                          {0,  -1},
                                          {0,  1}};
        int dis = 0;
        while (!q.empty()) {
            dis++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                int r = p.first, c = p.second;
                for (auto d: directions) {
                    int dr = r + d[0], dc = c + d[1];
                    if (dr < 0 || dr == m || dc < 0 || dc == n || rooms[dr][dc] != INT_MAX) {
                        continue;
                    }
                    rooms[dr][dc] = dis;
                    q.push({dr, dc});
                }
            }
        }
    }
};
