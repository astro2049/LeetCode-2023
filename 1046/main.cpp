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
    int lastStoneWeight(vector<int> &stones) {
        priority_queue<int> q;
        for (auto s: stones) {
            q.push(s);
        }
        while (q.size() >= 2) {
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            if (x == y) {
                continue;
            } else {
                q.push(y - x);
            }
        }
        return q.size() == 1 ? q.top() : 0;
    }
};