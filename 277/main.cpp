#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

/* The knows API is defined for you. */
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for (int i = 1; i < n; i++) {
            if (knows(candidate, i)) {
                candidate = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i == candidate) {
                continue;
            }
            if (!knows(candidate, i) && knows(i, candidate)) {
                continue;
            } else {
                return -1;
            }
        }
        return candidate;
    }
};

class Solution1 {
public:
    vector<vector<int>> m;

    int findCelebrity(int n) {
        m.resize(n, vector<int>(n));
        int candidate = 0;
        for (int i = 1; i < n; i++) {
            if (knowsMemo(candidate, i)) {
                candidate = i;
                m[candidate][i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i == candidate) {
                continue;
            }
            if (!knowsMemo(candidate, i) && knowsMemo(i, candidate)) {
                continue;
            } else {
                return -1;
            }
        }
        return candidate;
    }

    bool knowsMemo(int i, int j) {
        if (m[i][j] == 0) {
            m[i][j] = knows(i, j) ? 1 : -1;
        }
        return m[i][j] == 1;
    }
};

class Solution2 {
public:
    int n;

    int findCelebrity(int pn) {
        this->n = pn;
        for (int i = 0; i < n; i++) {
            if (isCelebrity(i)) {
                return i;
            }
        }
        return -1;
    }

    bool isCelebrity(int i) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (!knows(i, j) && knows(j, i)) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};
