//Problem Link: https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/description
//Date: 05/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; k++) 
        {
            long long target = (long long)num1 - 1LL * k * num2;

            if (target < k){
               continue;  // must be at least k
            } 
            if (__builtin_popcountll(target) <= k) 
            {
                return k;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    // Example 1
    int num1 = 3, num2 = -2;
    cout << "Input: num1 = " << num1 << ", num2 = " << num2 << endl;
    cout << "Output: " << sol.makeTheIntegerZero(num1, num2) << endl;

    // Example 2
    num1 = 5, num2 = 7;
    cout << "Input: num1 = " << num1 << ", num2 = " << num2 << endl;
    cout << "Output: " << sol.makeTheIntegerZero(num1, num2) << endl;

    // You can add more test cases here
    num1 = 10, num2 = -3;
    cout << "Input: num1 = " << num1 << ", num2 = " << num2 << endl;
    cout << "Output: " << sol.makeTheIntegerZero(num1, num2) << endl;

    return 0;
}
