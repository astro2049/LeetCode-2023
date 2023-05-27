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
    vector<bool> visit;

    bool validTree(int n, vector<vector<int>> &edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        net = vector<vector<int>>(n);
        visit.resize(n, false);
        for (auto edge: edges) {
            net[edge[0]].push_back(edge[1]);
            net[edge[1]].push_back(edge[0]);
        }
        dfs(0);
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                return false;
            }
        }
        return true;
    }

    void dfs(int i) {
        if (visit[i]) {
            return;
        }
        visit[i] = true;
        for (auto neighbor: net[i]) {
            dfs(neighbor);
        }
    }
};

class Solution1 {
public:
    vector<int> pars;
    vector<int> ranks;

    bool validTree(int n, vector<vector<int>> &edges) {
        for (int i = 0; i < n; i++) {
            pars.push_back(i);
        }
        ranks = vector<int>(n, 1);
        int comps = n;
        for (auto edge: edges) {
            if (unionx(edge[0], edge[1])) {
                comps--;
            } else {
                return false;
            }
        }
        return comps == 1;
    }

    int find(int n) {
        while (n != pars[n]) {
            pars[n] = pars[pars[n]];
            n = pars[n];
        }
        return n;
    }

    int unionx(int a, int b) {
        int p1 = find(a), p2 = find(b);
        if (p1 == p2) {
            return 0;
        }
        if (ranks[p1] > ranks[p2]) {
            pars[p2] = p1;
            ranks[p1] += ranks[p2];
        } else {
            pars[p1] = p2;
            ranks[p2] += ranks[p1];
        }
        return 1;
    }
};
