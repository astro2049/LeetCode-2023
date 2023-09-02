#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        sort(points.begin(), points.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });
        int shots = 1;
        for (int i = 0, j = 1; i < points.size() && j < points.size();) {
            if (points[i][1] >= points[j][0]) {
                j++;
            } else {
                shots++;
                i = j;
                j = i + 1;
            }
        }
        return shots;
    }
};
