// Problem Link: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description
// Date: 03/01/2025
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1000000007;

        // A = number of ways with 2-color pattern
        // B = number of ways with 3-color pattern
        long long A = 6, B = 6;

        for (int i = 2; i <= n; i++) {
            long long newA = (2 * A + 2 * B) % MOD;
            long long newB = (2 * A + 3 * B) % MOD;
            A = newA;
            B = newB;
        }

        return (A + B) % MOD;
    }
};

int main() {
    Solution sol;

    int n = 3;

    cout << "Number of ways to paint the grid for n = " << n << " is: ";
    cout << sol.numOfWays(n) << endl;

    return 0;
}

