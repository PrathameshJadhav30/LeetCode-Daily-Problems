//Problem Link: https://leetcode.com/problems/triangle/description
//Date: 25/09/2025
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // dp array to store the minimum path sum for the current row
        vector<int> dp(triangle.back()); // start with the last row

        // Start from second-last row and move upwards
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
            }
        }

        // The top element will have the minimum path sum
        return dp[0];
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> triangle1 = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    cout << "Minimum path sum (Example 1): " << sol.minimumTotal(triangle1) << endl;

    // Example 2
    vector<vector<int>> triangle2 = {
        {-10}
    };
    cout << "Minimum path sum (Example 2): " << sol.minimumTotal(triangle2) << endl;

    return 0;
}
