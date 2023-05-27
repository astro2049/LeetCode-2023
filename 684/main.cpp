#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> pars;
    vector<int> ranks;

    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = edges.size();
        for (int i = 0; i < n + 1; i++) {
            pars.push_back(i);
        }
        ranks = vector<int>(n + 1);
        for (int i = 0; i < n; i++) {
            if (!unionx(edges[i][0], edges[i][1])) {
                return edges[i];
            }
        }
        return {};
    }

    int find(int n) {
        while (n != pars[n]) {
            pars[n] = pars[pars[n]];
            n = pars[n];
        }
        return n;
    }

    bool unionx(int v1, int v2) {
        int p1 = find(v1);
        int p2 = find(v2);
        if (p1 == p2) {
            return false;
        }
        if (ranks[p1] > ranks[p2]) {
            pars[p2] = p1;
            ranks[p1] += ranks[p2];
        } else {
            pars[p1] = p2;
            ranks[p2] += ranks[p1];
        }
        return true;
    }
};
