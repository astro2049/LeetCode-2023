#include <iostream>
#include "unordered_map"
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> m;

    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        if (m[key].empty()) {
            return "";
        } else {
            int i = 0, j = m[key].size() - 1;
            int index = -1;
            while (i <= j) {
                int mid = (i + j) / 2;
                if (m[key][mid].first <= timestamp) {
                    index = mid;
                    i = mid + 1;
                } else {
                    j = mid - 1;
                }
            }
            if (index == -1) {
                return "";
            } else {
                return m[key][index].second;
            }
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
