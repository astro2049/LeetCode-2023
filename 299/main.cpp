#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> ms(10), mg(10);
        int bulls = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                ms[secret[i] - '0']++;
                mg[guess[i] - '0']++;
            }
        }
        int cows = 0;
        for (int i = 0; i < 10; i++) {
            cows += min(ms[i], mg[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
