#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
            return a[0] < b[0];
        });
        int count = 0;
        for (int i = 0, j = 1; j < intervals.size(); j++) {
            auto last = intervals[i], cur = intervals[j];
            if (cur[0] >= last[1]) {
                i = j;
                continue;
            } else {
                count++;
                if (cur[1] > last[1]) {
                    continue;
                } else {
                    i = j;
                }
            }
        }
        return count;
    }
};
