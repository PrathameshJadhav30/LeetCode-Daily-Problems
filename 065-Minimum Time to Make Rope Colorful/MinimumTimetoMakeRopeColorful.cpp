//Problem Link: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description
// Date: 03/11/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size(), totalCost = 0;

        for (int i = 1; i < n; i++) {
            int maxTime = 0;
            // Traverse group of same-colored balloons
            while (i < n && colors[i] == colors[i - 1]) {
                totalCost += neededTime[i - 1];      // add current cost
                maxTime = max(maxTime, neededTime[i - 1]); // track max time in group
                ++i;
            }
            totalCost += neededTime[i - 1];
            maxTime = max(maxTime, neededTime[i - 1]);
            if (maxTime != 0) totalCost -= maxTime; // remove one with max time
        }
        return totalCost;
    }
};

int main() {
    Solution sol;

    string colors = "abaac";
    vector<int> neededTime = {1, 2, 3, 4, 5};

    cout << "Colors: " << colors << endl;
    cout << "Needed Time: ";
    for (int t : neededTime) cout << t << " ";
    cout << endl;

    int result = sol.minCost(colors, neededTime);
    cout << "\nMinimum Total Removal Time = " << result << endl;

    return 0;
}
