//Problem Link: https://leetcode.com/problems/water-bottles/description
//Date:1/10/2025
#include <iostream>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrank = numBottles;  // Start with all full bottles
        int emptyBottles = numBottles; // Initially, all bottles will become empty after drinking

        while (emptyBottles >= numExchange) {
            int newFull = emptyBottles / numExchange; // Exchange empty bottles for new full ones
            totalDrank += newFull;                    // Drink these new full bottles
            emptyBottles = emptyBottles % numExchange + newFull; // Update empty bottles
        }

        return totalDrank;
    }
};

int main() {
    Solution sol;
    int numBottles, numExchange;

    // Example 1
    numBottles = 9;
    numExchange = 3;
    cout << "Maximum bottles you can drink (Example 1): " 
         << sol.numWaterBottles(numBottles, numExchange) << endl;

    // Example 2
    numBottles = 15;
    numExchange = 4;
    cout << "Maximum bottles you can drink (Example 2): " 
         << sol.numWaterBottles(numBottles, numExchange) << endl;

    return 0;
}
