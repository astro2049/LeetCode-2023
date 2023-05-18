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
    int largestRectangleArea(vector<int> &heights) {
        stack<pair<int, int>> s;
        int maxArea = 0, area;
        for (int i = 0; i < heights.size(); i++) {
            if (s.empty()) {
                s.push({i, heights[i]});
            } else {
                int startI = i;
                while (!s.empty() && s.top().second > heights[i]) {
                    startI = s.top().first;
                    area = (i - s.top().first) * s.top().second;
                    maxArea = max(maxArea, area);
                    s.pop();
                }
                s.push({startI, heights[i]});
            }
        }
        int n = heights.size();
        while (!s.empty()) {
            area = (n - s.top().first) * s.top().second;
            maxArea = max(maxArea, area);
            s.pop();
        }
        return maxArea;
    }
};
