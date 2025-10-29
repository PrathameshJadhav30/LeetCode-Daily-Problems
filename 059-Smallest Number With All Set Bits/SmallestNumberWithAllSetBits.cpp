//Problem Link: https://leetcode.com/problems/smallest-number-with-all-set-bits/description
// Date: 29/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        while (n & (n + 1)) {
            n |= n + 1;
        }
        return n;
    }
};

int main() {
    Solution sol;
    
    int n = 6; 
    int result = sol.smallestNumber(n);
    
    cout << "Input: " << n << endl;
    cout << "Smallest number after performing the operation: " << result << endl;

    return 0;
}
