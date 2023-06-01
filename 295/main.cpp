#include <iostream>
#include "queue"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<>> smaller;
    priority_queue<int, vector<int>, greater<>> larger;
    int count = 0;

    MedianFinder() {

    }

    void addNum(int num) {
        count++;
        if (!larger.empty() && num >= larger.top()) {
            larger.push(num);
        } else {
            smaller.push(num);
        }
        if (smaller.size() < larger.size()) {
            smaller.push(larger.top());
            larger.pop();
        } else if (smaller.size() == larger.size() + 2) {
            larger.push(smaller.top());
            smaller.pop();
        }
    }

    double findMedian() {
        if (count % 2 == 1) {
            return smaller.top();
        } else {
            return double(smaller.top() + larger.top()) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
