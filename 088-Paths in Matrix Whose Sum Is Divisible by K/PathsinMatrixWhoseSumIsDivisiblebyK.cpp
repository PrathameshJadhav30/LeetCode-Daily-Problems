// Problem Link: https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description
// Date: 26/11/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1000000007;
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> prev(n, vector<int>(k)), curr(n, vector<int>(k));
        int sum = 0;

        // First row prefix sums
        for (int j = 0; j < n; j++) {
            sum = (sum + grid[0][j]) % k;
            prev[j][sum] = 1;
        }

        sum = grid[0][0] % k;

        // DP on grid
        for (int i = 1; i < m; i++) {
            sum = (sum + grid[i][0]) % k;
            fill(curr[0].begin(), curr[0].end(), 0);
            curr[0][sum] = 1;

            for (int j = 1; j < n; j++) {
                fill(curr[j].begin(), curr[j].end(), 0);
                int val = grid[i][j];

                for (int r = 0; r < k; r++) {
                    int nr = (r + val) % k;

                    curr[j][nr] = ( (long long)prev[j][r] + curr[j - 1][r] ) % MOD;
                }
            }

            swap(prev, curr);
        }

        return prev[n - 1][0];
    }
};

int main() {
   
    vector<vector<int>> grid = {
        {5, 2, 4},
        {3, 0, 5},
        {0, 7, 2}
    };
    int k = 3;

    Solution sol;
    cout << sol.numberOfPaths(grid, k) << endl;

    return 0;
}
