//Problem Link: https://leetcode.com/problems/water-bottles-ii/description
//Date: 2/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalDrunk = 0;          // Total bottles drunk
        int empty = 0;               // Empty bottles after drinking
        
        // Start drinking bottles until you can't exchange anymore
        while (numBottles > 0) {
            // Drink all available bottles
            totalDrunk += numBottles;
            empty += numBottles;
            numBottles = 0;

            // Try exchanging empty bottles
            while (empty >= numExchange) {
                empty -= numExchange;   // Spend empty bottles
                numBottles++;           // Get 1 new full bottle
                numExchange++;          // Exchange cost increases
            }
        }
        
        return totalDrunk;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    int numBottles1 = 13, numExchange1 = 6;
    cout << "Input: numBottles = " << numBottles1 
         << ", numExchange = " << numExchange1 << endl;
    cout << "Output: " << sol.maxBottlesDrunk(numBottles1, numExchange1) << endl;
    cout << "Expected: 15" << endl << endl;

    // Test Case 2
    int numBottles2 = 10, numExchange2 = 3;
    cout << "Input: numBottles = " << numBottles2 
         << ", numExchange = " << numExchange2 << endl;
    cout << "Output: " << sol.maxBottlesDrunk(numBottles2, numExchange2) << endl;
    cout << "Expected: 13" << endl << endl;

    // Custom Test Case
    int numBottles3 = 5, numExchange3 = 2;
    cout << "Input: numBottles = " << numBottles3 
         << ", numExchange = " << numExchange3 << endl;
    cout << "Output: " << sol.maxBottlesDrunk(numBottles3, numExchange3) << endl;

    return 0;
}
