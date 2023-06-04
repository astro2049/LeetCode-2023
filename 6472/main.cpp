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
    long long matrixSumQueries(int n, vector<vector<int>> &queries) {
        unordered_set<int> rs, cs;
        unsigned long long sum = 0;
        for (int i = queries.size() - 1; i >= 0; i--) {
            auto query = queries[i];
            if (query[0] == 1) {
                int row = query[1], val = query[2];
                if (rs.find(row) != rs.end()) {
                    continue;
                } else {
                    rs.insert(row);
                    sum += (n - cs.size()) * val;
                }
            } else {
                int col = query[1], val = query[2];
                if (cs.find(col) != cs.end()) {
                    continue;
                } else {
                    cs.insert(col);
                    sum += (n - rs.size()) * val;
                }
            }
        }
        return sum;
    }
};
