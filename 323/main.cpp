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

    int countComponents(int n, vector<vector<int>> &edges) {
        for (int i = 0; i < n; i++) {
            pars.push_back(i);
        }
        ranks = vector<int>(n, 1);
        int comps = n;
        for (auto edge: edges) {
            comps -= unionx(edge[0], edge[1]);
        }
        return comps;
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
