#include <iostream>
#include "vector"
#include "unordered_set"
#include "queue"
#include "cmath"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>> &points) { // Prim's algorithm - Minimum Spanning Tree
        int cost = 0;
        auto greater = [](const auto &a, const auto &b) {
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(greater)> minQ(greater);
        int cur = 0;
        for (int i = 1; i < points.size(); i++) {
            minQ.push({abs(points[i][0] - points[cur][0]) + abs(points[i][1] - points[cur][1]), i});
        }
        while (!minQ.empty()) {
            cost += minQ.top().first;
            cur = minQ.top().second;
            minQ.pop();
            vector<pair<int, int>> v;
            while (!minQ.empty()) {
                auto p = minQ.top();
                minQ.pop();
                v.emplace_back(min(p.first, abs(points[p.second][0] - points[cur][0]) +
                                            abs(points[p.second][1] - points[cur][1])), p.second);
            }
            for (auto p: v) {
                minQ.push(p);
            }
        }
        return cost;
    }
};
