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
    int minMeetingRooms(vector<vector<int>> &intervals) {
        vector<int> starts, ends;
        for (auto &interv: intervals) {
            starts.push_back(interv[0]);
            ends.push_back(interv[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int maxCount = 0, count = 0;
        for (int i = 0, j = 0; i < starts.size();) {
            if (starts[i] < ends[j]) {
                i++;
                count++;
                maxCount = max(maxCount, count);
            } else {
                j++;
                count--;
            }
        }
        return maxCount;
    }
};
