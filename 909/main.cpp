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
    int n;

    int snakesAndLadders(vector<vector<int>> &board) {
        n = board.size();
        int steps = 0;
        queue<int> q;
        vector<bool> visited(n * n + 1, false);
        q.push(1);
        visited[1] = true;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int sqaure = q.front();
                if (sqaure == n * n) {
                    return steps;
                }
                q.pop();
                for (int j = 1; j <= 6; j++) {
                    int next = sqaure + j;
                    if (next > n * n) {
                        break;
                    }
                    auto coord = sqaure2Coord(next);
                    int x = coord[0], y = coord[1];
                    if (board[x][y] != -1) {
                        next = board[x][y];
                    }
                    if (!visited[next]) {
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }

    vector<int> sqaure2Coord(int i) {
        int row = (i - 1) / n;
        int col = row % 2 == 0 ? (i - 1) % n : n - 1 - ((i - 1) % n);
        row = n - 1 - row;
        return {row, col};
    }
};
