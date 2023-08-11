#include <iostream>
#include "unordered_set"
#include <cstdlib>
#include "vector"
#include "unordered_map"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class RandomizedSet {
public:
    unordered_set<int> s;

    RandomizedSet() {
        srand(time(nullptr));
    }

    bool insert(int val) {
        if (s.find(val) != s.end()) {
            return false;
        } else {
            s.insert(val);
            return true;
        }
    }

    bool remove(int val) {
        if (s.find(val) == s.end()) {
            return false;
        } else {
            s.erase(val);
            return true;
        }
    }

    int getRandom() {
        int i = rand() % s.size();
        return vector<int>(s.begin(), s.end())[i];
    }
};

class RandomizedSet1 {
public:
    vector<int> nums;
    unordered_map<int, int> m;

    RandomizedSet1() {
        srand(time(nullptr));
    }

    bool insert(int val) {
        if (m.find(val) != m.end()) {
            return false;
        } else {
            nums.push_back(val);
            m[val] = nums.size() - 1;
            return true;
        }
    }

    bool remove(int val) {
        if (m.find(val) == m.end()) {
            return false;
        } else {
            nums[m[val]] = nums.back();
            m[nums.back()] = m[val];
            nums.pop_back();
            m.erase(val);
            return true;
        }
    }

    int getRandom() {
        int i = rand() % nums.size();
        return nums[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
