// Problem Link: https://leetcode.com/problems/delete-columns-to-make-sorted-iii/description
// Date: 22/12/2025
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();   // number of columns
        int m = strs.size();     // number of rows
        
        // dp[i] = length of longest valid non-decreasing column sequence ending at column i
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                bool ok = true;

                // check column j <= column i for all rows
                for (int r = 0; r < m; r++) {
                    if (strs[r][j] > strs[r][i]) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int maxLen = *max_element(dp.begin(), dp.end());
        return n - maxLen; // minimum deletions
    }
};

int main() {
    Solution sol;

    int m;
    cout << "Enter number of strings: ";
    cin >> m;

    vector<string> strs(m);
    cout << "Enter strings:\n";
    for (int i = 0; i < m; i++) {
        cin >> strs[i];
    }

    int result = sol.minDeletionSize(strs);
    cout << "\nMinimum columns to delete: " << result << endl;

    return 0;
}
