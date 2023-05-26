#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> net;
    vector<bool> visited;

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        net = vector<vector<int>>(numCourses);
        visited = vector<bool>(numCourses);
        for (auto p: prerequisites) {
            net[p[0]].push_back(p[1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int i) {
        if (visited[i]) {
            return false;
        }
        if (net[i].empty()) {
            return true;
        }
        visited[i] = true;
        for (auto pre: net[i]) {
            if (!dfs(pre)) {
                return false;
            }
        }
        visited[i] = false;
        net[i].clear();
        return true;
    }
};
