#include <iostream>
#include "vector"
#include "queue"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<>> q;
    int k;

    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        for (auto n: nums) {
            q.push(n);
        }
        while (q.size() > k) {
            q.pop();
        }
    }

    int add(int val) {
        q.push(val);
        if (q.size() > k) {
            q.pop();
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
