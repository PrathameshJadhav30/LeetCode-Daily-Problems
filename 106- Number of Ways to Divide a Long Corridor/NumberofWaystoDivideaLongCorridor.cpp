// Problem Link: https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/description
// Date: 14/12/2025
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    static const int mod = 1000000007;

    int numberOfWays(string corridor) {
        vector<int> pos;

        // Store positions of seats 'S'
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                pos.push_back(i);
            }
        }

        // If number of seats is odd or zero, no valid partition
        if (pos.size() == 0 || pos.size() % 2 != 0) {
            return 0;
        }

        long long res = 1;

        // Calculate ways by counting gaps between seat pairs
        for (int i = 2; i < pos.size(); i += 2) {
            int gap = pos[i] - pos[i - 1];
            res = (res * gap) % mod;
        }

        return (int)res;
    }
};

int main() {
    Solution sol;

    string corridor = "SSPPSPS";  
    

    int result = sol.numberOfWays(corridor);

    cout << "Corridor: " << corridor << endl;
    cout << "Number of ways to divide corridor: " << result << endl;

    return 0;
}
