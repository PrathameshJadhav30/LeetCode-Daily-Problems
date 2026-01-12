// Problem Link: https://leetcode.com/problems/minimum-time-visiting-all-points/description
// Date: 12/01/2026
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int ans = 0;
        for (int i = 1; i < p.size(); i++) {
            ans += max(
                abs(p[i][0] - p[i - 1][0]),
                abs(p[i][1] - p[i - 1][1])
            );
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> points = {
        {1, 1},
        {3, 4},
        {-1, 0}
    };

    // Function call
    int result = sol.minTimeToVisitAllPoints(points);

    // Output
    cout << "Minimum time to visit all points: " << result << endl;

    return 0;
}
