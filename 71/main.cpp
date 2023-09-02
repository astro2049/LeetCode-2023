#include <iostream>
#include "deque"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string simplifyPath(string path) {
        deque<string> q;
        for (int i = 0, j = 0; i < path.length() && j < path.length();) {
            if (path[j] == '/') {
                j++;
                continue;
            } else {
                i = j;
                while (j < path.length() && path[j] != '/') {
                    j++;
                }
                string x = path.substr(i, j - i);
                if (x == ".") {
                    continue;
                } else if (x == "..") {
                    if (!q.empty()) {
                        q.pop_back();
                    }
                } else {
                    q.push_back(x);
                }
            }
        }
        string sPath;
        while (!q.empty()) {
            sPath += "/";
            sPath += q.front();
            q.pop_front();
        }
        if (sPath.length() == 0) {
            sPath = "/";
        }
        return sPath;
    }
};
