//Problem Link: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description
//Date: 07/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        
        // If n is odd, include 0
        if (n % 2 == 1) {
            result.push_back(0);
            n--; // now n is even
        }
        
        // Add pairs of numbers
        for (int i = 1; i <= n / 2; i++) {
            result.push_back(i);
            result.push_back(-i);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<int> ans = sol.sumZero(n);
    for (int x : ans){
      cout << x << " ";
    } 
    cout << endl;
    return 0;
}
