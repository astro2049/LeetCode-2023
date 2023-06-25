#include <iostream>
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int countBeautifulPairs(vector<int> &nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (__gcd(stoi(to_string(nums[i]).substr(0, 1)), nums[j] % 10) == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};
