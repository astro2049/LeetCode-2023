#include <iostream>
#include "vector"
#include "algorithm"
#include "stack"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), [](const pair<int, int> a, const pair<int, int> b) {
            return a.first > b.first;
        });
        stack<pair<int, int>> s;
        for (auto &car: cars) {
            if (s.empty()) {
                s.push(car);
            } else {
                auto p = s.top();
                if ((float) (target - car.first) / car.second <= (float) (target - p.first) / p.second) {

                } else {
                    s.push(car);
                }
            }
        }
        return s.size();
    }
};
