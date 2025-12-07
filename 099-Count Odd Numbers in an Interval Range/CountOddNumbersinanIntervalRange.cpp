// Problem Link: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description
// Date: 07/12/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        return (high - low + 1 + low % 2) / 2;
    }
};

int main() {
    Solution obj;
    
    int low = 3;         
    int high = 7;        
    
    int result = obj.countOdds(low, high);

    cout << "Odd numbers between " << low << " and " << high << " = " << result << endl;

    return 0;
}
