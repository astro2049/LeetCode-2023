#include <iostream>
#include "vector"
#include "unordered_map"
#include "queue"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int ticketCount;
    unordered_map<string, priority_queue<string, vector<string>, greater<>>> map;
    vector<string> res;

    vector<string> findItinerary(vector<vector<string>> &tickets) {
        ticketCount = tickets.size();
        for (auto t: tickets) {
            map[t[0]].push(t[1]);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(const string &airport) {
        while (!map[airport].empty()) {
            string to = map[airport].top();
            map[airport].pop();
            dfs(to);
        }
        res.push_back(airport);
    }
};
