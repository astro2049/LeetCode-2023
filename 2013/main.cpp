#include <iostream>
#include "vector"
#include "cmath"
#include "unordered_map"
#include "unordered_set"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class DetectSquares {
public:
    unordered_map<int, unordered_set<int>> xs, ys;
    vector<vector<int>> map;

    DetectSquares() {
        map.resize(1001, vector<int>(1001));
    }

    void add(vector<int> point) {
        int x = point[0], y = point[1];
        xs[x].insert(y);
        ys[y].insert(x);
        map[x][y]++;
    }

    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int count = 0;
        for (auto yCoord: xs[x]) {
            if (yCoord == point[1]) {
                continue;
            }
            for (auto xCoord: ys[y]) {
                if (xCoord == point[0]) {
                    continue;
                }
                if (abs(point[1] - yCoord) == abs(point[0] - xCoord)) {
                    count += map[x][yCoord] * map[xCoord][y] * map[xCoord][yCoord];
                }
            }
        }
        return count;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */