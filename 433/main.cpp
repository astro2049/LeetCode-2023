#include <iostream>
#include "vector"
#include "unordered_map"
#include "queue"
#include "unordered_set"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string> &bank) {
        unordered_map<string, vector<string>> m;
        bool hasStartGene = false;
        for (const auto &s: bank) {
            if (s == startGene) {
                hasStartGene = true;
            }
        }
        if (!hasStartGene) {
            bank.push_back(startGene);
        }
        for (int i = 0; i < bank.size(); i++) {
            for (int j = i + 1; j < bank.size(); j++) {
                if (canTransfrom(bank[i], bank[j])) {
                    m[bank[i]].push_back(bank[j]);
                    m[bank[j]].push_back(bank[i]);
                }
            }
        }
        queue<string> q;
        unordered_set<string> visited;
        q.push(startGene);
        visited.insert(startGene);
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                const auto &gene = q.front();
                q.pop();
                if (gene == endGene) {
                    return steps;
                }
                for (const auto &next: m[gene]) {
                    if (visited.find(next) == visited.end()) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
            steps++;
        }
        return -1;
    }

    bool canTransfrom(const string &x, const string &y) {
        int diff = 0;
        for (int i = 0; i < 8; i++) {
            if (x[i] != y[i]) {
                diff++;
                if (diff == 2) {
                    return false;
                }
            }
        }
        return diff == 1;
    }
};
