#include <iostream>
#include "vector"
#include "queue"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        vector<int> v(26);
        for (auto t: tasks) {
            v[t - 'A']++;
        }
        for (int i = 0; i < 26; i++) {
            if (v[i] != 0) {
                pq.push(v[i]);
            }
        }
        int time = 0;
        while (!pq.empty() || !q.empty()) {
            time++;
            if (!pq.empty()) {
                int t = pq.top();
                t--;
                pq.pop();
                if (t != 0) {
                    q.push({t, time + n});
                }
            }
            if (!q.empty()) {
                auto t = q.front();
                if (time == t.second) {
                    q.pop();
                    pq.push(t.first);
                }
            }
        }
        return time;
    }
};
