// Problem Link: https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/description
// Date: 17/01/2026

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    using ll = long long;

    ll largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        int s = 0;
        int n = bl.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                // Intersection rectangle
                int minX = max(bl[i][0], bl[j][0]);
                int maxX = min(tr[i][0], tr[j][0]);
                int minY = max(bl[i][1], bl[j][1]);
                int maxY = min(tr[i][1], tr[j][1]);

                // Check if intersection exists
                if (minX < maxX && minY < maxY) {
                    int len = min(maxX - minX, maxY - minY);
                    s = max(s, len);
                }
            }
        }
        return (ll)s * s;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> bottomLeft = {
        {1, 1},
        {2, 2},
        {3, 1}
    };

    vector<vector<int>> topRight = {
        {3, 3},
        {4, 4},
        {5, 3}
    };

    long long result = sol.largestSquareArea(bottomLeft, topRight);
    cout << "Largest square area: " << result << endl;

    return 0;
}