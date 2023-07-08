#include <iostream>
#include "vector"
#include "unordered_map"
#include "unordered_set"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>> &coordinates) {
        vector<long long> res(5);
        unordered_map<int, unordered_set<int>> map;
        for (const auto &coord: coordinates) {
            map[coord[0]].insert(coord[1]);
        }
        unordered_map<int, unordered_set<int>> visited;
        vector<vector<int>> directions = {{-1, -1},
                                          {-1, 0},
                                          {0,  -1},
                                          {0,  0}};
        for (const auto &pair: map) {
            int x = pair.first;
            for (const auto &y: pair.second) {
                for (const auto &direc: directions) {
                    int xS = x + direc[0], yS = y + direc[1];
                    if (xS < 0 || xS == m - 1 || xS == m || yS < 0 || yS == n - 1 || yS == n) {
                        continue;
                    } else {
                        if (visited.find(xS) != visited.end() && visited[xS].find(yS) != visited[xS].end()) {
                            continue;
                        }
                        int count = 0;
                        for (int i = xS; i <= xS + 1; i++) {
                            for (int j = yS; j <= yS + 1; j++) {
                                if (map.find(i) != map.end() && map[i].find(j) != map[i].end()) {
                                    count++;
                                }
                            }
                        }
                        res[count]++;
                        visited[xS].insert(yS);
                    }
                }
            }
        }
        long long totalCount = ((long long) m - 1) * ((long long) n - 1);
        res[0] = totalCount - res[1] - res[2] - res[3] - res[4];
        return res;
    }
};
