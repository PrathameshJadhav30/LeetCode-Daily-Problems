//Problem Link: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/description
//Date: 02/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // Sort points: x ascending, y descending
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1]; // y descending
            return a[0] < b[0];                  // x ascending
        });

        int pairCount = 0;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            int upperY = points[i][1];
            int lowerYLimit = INT_MIN;

            for (int j = i + 1; j < n; j++) {
                int currentY = points[j][1];

                if (currentY <= upperY && currentY > lowerYLimit) {
                    pairCount++;
                    lowerYLimit = currentY;

                    if (currentY == upperY) {
                        break;
                    }
                }
            }
        }

        return pairCount;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<vector<int>> points = {{1,3},{2,2},{2,1},{3,3}};
    
    int result = sol.numberOfPairs(points);
    cout << "Number of valid pairs: " << result << endl;

    return 0;
}
