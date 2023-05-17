#include <iostream>
#include "vector"
#include "stack"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<int> warmer(temperatures.size());
        stack<int> s;
        for (int i = 0; i < temperatures.size(); i++) {
            if (s.empty()) {
                s.push(i);
            } else {
                if (temperatures[i] <= temperatures[s.top()]) {
                    s.push(i);
                } else {
                    while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                        warmer[s.top()] = i - s.top();
                        s.pop();
                    }
                    s.push(i);
                }
            }
        }
        while (!s.empty()) {
            warmer[s.top()] = 0;
            s.pop();
        }
        return warmer;
    }
};
