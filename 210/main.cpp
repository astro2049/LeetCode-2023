#include <iostream>
#include "vector"
#include "unordered_set"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> net;
    unordered_set<int> visit, cycle;
    vector<int> order;

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        net = vector<vector<int>>(numCourses);
        for (auto p: prerequisites) {
            net[p[0]].push_back(p[1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) {
                return {};
            }
        }
        return order;
    }

    bool dfs(int i) {
        if (cycle.find(i) != cycle.end()) {
            return false;
        }
        if (visit.find(i) != visit.end()) {
            return true;
        }
        cycle.insert(i);
        for (auto pre: net[i]) {
            if (!dfs(pre)) {
                return false;
            }
        }
        cycle.erase(i);
        visit.insert(i);
        order.push_back(i);
        return true;
    }
};
