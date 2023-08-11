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
    int hIndex(vector<int> &cits) {
        sort(cits.begin(), cits.end());
        int h = 0;
        for (int i = cits.size() - 1; i >= 0; i--) {
            if (cits[i] > h) {
                h++;
            } else {
                break;
            }
        }
        return h;
    }
};

class Solution1 {
public:
    int hIndex(vector<int> &cits) {
        int l = 0, r = cits.size();
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (goBigger(mid, cits)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }

    bool goBigger(int h, vector<int> &cits) {
        int count = 0;
        for (auto &c: cits) {
            if (c >= h) {
                count++;
            }
        }
        return count >= h;
    }
};
