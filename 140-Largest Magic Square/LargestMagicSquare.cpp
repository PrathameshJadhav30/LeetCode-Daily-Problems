// Problem Link: https://leetcode.com/problems/largest-magic-square/description
// Date: 18/01/2026
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    bool isValid(vector<vector<int>>& g, int i, int j, int k) {
        int sum = 0;

        // Check row sums
        for (int x = i; x < i + k; x++) {
            int s = 0;
            for (int y = j; y < j + k; y++)
                s += g[x][y];

            if (x == i) sum = s;
            else if (sum != s) return false;
        }

        // Check column sums
        for (int y = j; y < j + k; y++) {
            int s = 0;
            for (int x = i; x < i + k; x++)
                s += g[x][y];

            if (sum != s) return false;
        }

        // Check main diagonal
        int s = 0;
        for (int d = 0; d < k; d++)
            s += g[i + d][j + d];

        if (sum != s) return false;

        // Check anti-diagonal
        s = 0;
        for (int d = 0; d < k; d++)
            s += g[i + d][j + k - 1 - d];

        if (sum != s) return false;

        return true;
    }

public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 1;

        for (int k = 2; k <= min(m, n); k++) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    if (isValid(grid, i, j, k))
                        res = k;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> grid = {
        {7, 1, 4, 5, 6},
        {2, 5, 1, 6, 4},
        {1, 5, 4, 3, 2},
        {1, 2, 7, 3, 4}
    };

    cout << "Largest Magic Square Size: "
         << sol.largestMagicSquare(grid) << endl;

    return 0;
}
