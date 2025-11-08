//Problem Link: https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/description
//Date: 08/11/2025
#include <iostream>
using namespace std;

class Solution {
public:
    // Function to calculate minimum number of bit operations
    int minimumOneBitOperations(int n) {
        int res = 0;
        while (n) {
            res ^= n;  // XOR accumulate
            n >>= 1;   // Right shift n by 1
        }
        return res;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter an integer n: ";
    cin >> n;

    int result = sol.minimumOneBitOperations(n);
    cout << "Minimum number of bit operations = " << result << endl;

    return 0;
}
