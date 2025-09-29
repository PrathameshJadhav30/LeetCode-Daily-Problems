//Problem Link: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description
//Date: 29/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Consider length of subpolygon from 3 to n
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                // Choose a vertex k between i and j to form a triangle
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[k] * values[j]);
                }
            }
        }
        return dp[0][n-1];
    }
};

int main() {
    Solution sol;
    vector<int> values1 = {1,2,3};
    vector<int> values2 = {3,7,4,5};
    vector<int> values3 = {1,3,1,4,1,5};

    cout << "Minimum Score (values1): " << sol.minScoreTriangulation(values1) << endl; // 6
    cout << "Minimum Score (values2): " << sol.minScoreTriangulation(values2) << endl; // 144
    cout << "Minimum Score (values3): " << sol.minScoreTriangulation(values3) << endl; // 13

    return 0;
}
