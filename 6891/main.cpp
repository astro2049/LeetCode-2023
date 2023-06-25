#include <iostream>
#include "vector"
#include "algorithm"
#include "list"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions) {
        vector<vector<int>> robots;
        int lCount = 0;
        for (int i = 0; i < positions.size(); i++) {
            if (directions[i] == 'L') {
                lCount++;
            }
            robots.push_back({i, positions[i], healths[i], directions[i] == 'L' ? -1 : 1});
        }
        int rCount = directions.size() - lCount;
        sort(robots.begin(), robots.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });
        list<vector<int>> l_robots(robots.begin(), robots.end());
        auto it = l_robots.begin();
        for (; it != l_robots.end();) {
            if (lCount == 0 || rCount == 0) {
                break;
            }
            auto next = it;
            next++;
            if (next == l_robots.end()) {
                it++;
                continue;
            }
            if ((*it)[3] == 1 && (*next)[3] == -1) {
                if ((*it)[2] == (*next)[2]) {
                    auto cur = it;
                    if (it != l_robots.begin()) {
                        it--;
                        next++;
                        l_robots.erase(cur, next);
                    } else {
                        next++;
                        l_robots.erase(cur, next);
                        it = l_robots.begin();
                    }
                } else if ((*it)[2] > (*next)[2]) {
                    (*it)[2]--;
                    l_robots.erase(next);
                } else {
                    (*next)[2]--;
                    auto cur = it;
                    if (it != l_robots.begin()) {
                        it--;
                        l_robots.erase(cur);
                    } else {
                        l_robots.erase(cur);
                        it = l_robots.begin();
                    }
                }
            } else {
                it++;
            }
        }
        vector<int> res;
        robots = vector<vector<int>>(l_robots.begin(), l_robots.end());
        sort(robots.begin(), robots.end(), [](const auto &a, const auto &b) {
            return a[0] < b[0];
        });
        for (auto r: robots) {
            res.push_back(r[2]);
        }
        return res;
    }
};
