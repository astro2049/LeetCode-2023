#include <iostream>
#include "stack"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class MyQueue {
public:
    stack<int> in, aux;

    MyQueue() {

    }

    void push(int x) {
        while (!in.empty()) {
            aux.push(in.top());
            in.pop();
        }
        in.push(x);
        while (!aux.empty()) {
            in.push(aux.top());
            aux.pop();
        }
    }

    int pop() {
        int ret = in.top();
        in.pop();
        return ret;
    }

    int peek() {
        return in.top();
    }

    bool empty() {
        return in.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
