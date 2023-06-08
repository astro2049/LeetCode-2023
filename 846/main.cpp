#include <iostream>
#include "vector"
#include "algorithm"
#include "unordered_map"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        sort(hand.begin(), hand.end());
        unordered_map<int, int> m;
        for (auto &card: hand) {
            m[card]++;
        }
        for (int i = 0; i < hand.size(); i++) {
            int card = hand[i];
            if (m.find(card) == m.end()) {
                continue;
            }
            m[card]--;
            if (m[card] == 0) {
                m.erase(card);
            }
            for (int j = 1; j < groupSize; j++) {
                card++;
                if (m.find(card) != m.end()) {
                    m[card]--;
                    if (m[card] == 0) {
                        m.erase(card);
                    }
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
