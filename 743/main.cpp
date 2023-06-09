#include <iostream>
#include "vector"
#include "queue"
#include "unordered_set"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        vector<vector<pair<int, int>>> map(n + 1);
        for (auto t: times) {
            map[t[0]].emplace_back(t[1], t[2]);
        }
        unordered_set<int> visit;
        auto greater = [](const auto &a, const auto &b) {
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(greater)> minQ(greater);
        minQ.push({0, k});
        int time = 0;
        while (!minQ.empty()) {
            auto p = minQ.top();
            minQ.pop();
            if (visit.find(p.second) != visit.end()) {
                continue;
            }
            visit.insert(p.second);
            time = p.first;
            for (auto to: map[p.second]) {
                if (visit.find(to.first) == visit.end()) {
                    minQ.push({p.first + to.second, to.first});
                }
            }
        }
        return visit.size() == n ? time : -1;
    }
};
