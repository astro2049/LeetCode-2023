#include <iostream>
#include "vector"
#include "queue"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });
        return {points.begin(), points.begin() + k};
    }
};

class Solution1 {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        auto cmp = [](vector<int> a, vector<int> b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        for (auto point: points) {
            q.push(point);
            if (q.size() > k) {
                q.pop();
            }
        }
        vector<vector<int>> res;
        while (!q.empty()) {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};
