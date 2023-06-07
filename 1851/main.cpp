#include <iostream>
#include "vector"
#include "unordered_map"
#include "set"
#include "queue"
#include "algorithm"

using namespace std;


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < queries.size(); i++) {
            m[queries[i]].push_back(i);
        }
        vector<int> res(queries.size());
        set<int> s(queries.begin(), queries.end());
        queries = {s.begin(), s.end()};
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
            return a[0] < b[0];
        });
        auto greater = [](const auto &a, const auto &b) {
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(greater)> minQ(greater);
        for (int i = 0, j = 0; j < queries.size();) {
            if (i < intervals.size() && intervals[i][0] <= queries[j]) {
                auto interv = intervals[i];
                minQ.push({interv[1] - interv[0] + 1, interv[1]});
                i++;
            } else {
                int queRes = -1;
                while (!minQ.empty()) {
                    if (minQ.top().second >= queries[j]) {
                        queRes = minQ.top().first;
                        break;
                    } else {
                        minQ.pop();
                    }
                }
                for (auto is: m[queries[j]]) {
                    res[is] = queRes;
                }
                j++;
            }
        }
        return res;
    }
};
