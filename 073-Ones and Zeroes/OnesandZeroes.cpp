//Problem Link: https://leetcode.com/problems/ones-and-zeroes/description
// Date: 11/11/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // dp[i][j] = max number of strings that can be formed with i zeros and j ones
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto& str : strs) {
            int c0 = count(str.begin(), str.end(), '0');
            int c1 = str.size() - c0;

            // Update dp in reverse to avoid using one string multiple times
            for (int i = m; i >= c0; --i) {
                for (int j = n; j >= c1; --j) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - c0][j - c1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution sol;

    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;

    int result = sol.findMaxForm(strs, m, n);

    cout << "Maximum number of strings that can be formed = " << result << endl;

    return 0;
}
