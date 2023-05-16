#include <iostream>
#include "vector"
#include "unordered_map"
#include "unordered_set"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool uniqueOccurrences(vector<int> &arr) {
        unordered_map<int, int> m;
        for (int n: arr) {
            m[n]++;
        }
        unordered_set<int> occurs;
        for (auto pair: m) {
            if (occurs.find(pair.second) == occurs.end()) {
                occurs.insert(pair.second);
            } else {
                return false;
            }
        }
        return true;
    }
};
