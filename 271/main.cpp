#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs) {
        string es;
        for (string s: strs) {
            string len = to_string(s.length());
            for (int i = 0; i < 10 - len.length(); i++) {
                es += "0";
            }
            es += len;
            es += s;
        }
        return es;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> v;
        for (int i = 0; i < s.length();) {
            int len = stoi(s.substr(i, 10));
            i += 10;
            v.emplace_back(s.substr(i, len));
            i += len;
        }
        return v;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
