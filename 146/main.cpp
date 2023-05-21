#include <iostream>
#include "unordered_map"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

struct Node {
    int key;
    int value;
    Node *prev;
    Node *next;
};

class LRUCache {
public:
    int capacity;
    Node *lru = new Node(), *mru = new Node();
    unordered_map<int, Node *> m;

    LRUCache(int capacity) {
        this->capacity = capacity;
        lru->next = mru;
        mru->prev = lru;
    }

    void remove(Node *n) {
        Node *prev = n->prev, *next = n->next;
        prev->next = next, next->prev = prev;
    }

    void insert(Node *n) {
        Node *prev = mru->prev, *next = mru;
        n->prev = prev, n->next = next;
        prev->next = n, next->prev = n;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            Node *n = m[key];
            remove(n);
            insert(n);
            return m[key]->value;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node *n = m[key];
            n->value = value;
            remove(n);
            insert(n);
        } else {
            if (m.size() == capacity) {
                Node *e = lru->next;
                m.erase(e->key);
                remove(e);
            }
            Node *n = new Node();
            n->key = key, n->value = value;
            insert(n);
            m[key] = n;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
