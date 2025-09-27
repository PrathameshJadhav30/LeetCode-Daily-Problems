//Problem Link: https://leetcode.com/problems/largest-triangle-area/description
//Date: 27/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxArea = 0.0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    double x1 = points[i][0], y1 = points[i][1];
                    double x2 = points[j][0], y2 = points[j][1];
                    double x3 = points[k][0], y3 = points[k][1];

                    // Shoelace formula
                    double area = fabs(x1 * (y2 - y3) +
                                       x2 * (y3 - y1) +
                                       x3 * (y1 - y2)) / 2.0;

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> points1 = {{0,0},{0,1},{1,0},{0,2},{2,0}};
    cout << "Largest Triangle Area (Example 1): " 
         << fixed << setprecision(5) 
         << sol.largestTriangleArea(points1) << endl;

    // Example 2
    vector<vector<int>> points2 = {{1,0},{0,0},{0,1}};
    cout << "Largest Triangle Area (Example 2): " 
         << fixed << setprecision(5) 
         << sol.largestTriangleArea(points2) << endl;

    return 0;
}
