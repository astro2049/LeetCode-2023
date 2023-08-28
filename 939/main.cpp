#include <iostream>
#include "vector"
#include "unordered_set"
#include "unordered_map"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int minAreaRect(vector<vector<int>> &points) {
        unordered_map<int, unordered_set<int>> yPoints;
        unordered_map<int, unordered_set<int>> xPoints;
        for (const auto &point: points) {
            int x = point[0], y = point[1];
            xPoints[x].insert(y);
            yPoints[y].insert(x);
        }
        int minArea = INT_MAX;
        for (int i = 0; i < points.size(); i++) {
            const auto &point = points[i];
            int x = point[0], y = point[1];
            for (int j = i + 1; j < points.size(); j++) {
                const auto &diagPoint = points[j];
                int xx = diagPoint[0], yy = diagPoint[1];
                if (x == xx || y == yy) {
                    continue;
                }
                if (xPoints[x].find(yy) != xPoints[x].end() && yPoints[y].find(xx) != yPoints[y].end()) {
                    minArea = min(minArea, abs(xx - x) * abs(yy - y));
                }
            }
        }
        return minArea == INT_MAX ? 0 : minArea;
    }
};

class Solution1 {
public:
    int minAreaRect(vector<vector<int>> &points) {
        unordered_map<int, unordered_set<int>> horPoints;
        unordered_map<int, unordered_set<int>> verPoints;
        for (const auto &point: points) {
            int x = point[0], y = point[1];
            horPoints[y].insert(x);
            verPoints[x].insert(y);
        }
        int minArea = INT_MAX;
        for (const auto &point: points) {
            int x = point[0], y = point[1];
            for (const auto &yy: verPoints[x]) {
                if (yy == y) {
                    continue;
                }
                for (const auto &xx: horPoints[y]) {
                    if (xx == x) {
                        continue;
                    }
                    if (verPoints[xx].find(yy) != verPoints[xx].end()) {
                        minArea = min(minArea, abs(xx - x) * abs(yy - y));
                    }
                }
            }
        }
        return minArea == INT_MAX ? 0 : minArea;
    }
};
