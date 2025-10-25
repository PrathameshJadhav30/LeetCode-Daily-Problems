//Problem Link: https://leetcode.com/problems/calculate-money-in-leetcode-bank/description
// Date: 25/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triSum(int n) { 
        return (n * (n + 1)) >> 1; // Same as n*(n+1)/2
    }

    int totalMoney(int days) {
        int nWeeks = days / 7;
        int rDays = days % 7;       

        // Formula derived from weekly increasing deposits pattern
        return triSum(days) - 42 * triSum(nWeeks - 1) - 6 * nWeeks * rDays;
    }
};

int main() {
    Solution obj;
    int days = 20;  
    cout << "Total money after " << days << " days: " << obj.totalMoney(days) << endl;
    return 0;
}
