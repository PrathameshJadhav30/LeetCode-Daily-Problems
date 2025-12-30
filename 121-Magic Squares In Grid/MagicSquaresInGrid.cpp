// Problem Link: https://leetcode.com/problems/magic-squares-in-grid/description
// Date: 30/12/2025
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size(), ans = 0;
        if (r < 3 || c < 3) return 0;

        for (int i = 0; i + 2 < r; i++) {
            for (int j = 0; j + 2 < c; j++) {

                bool used[10] = {false};
                bool ok = true;

                // Check numbers 1 to 9 exactly once
                for (int x = 0; x < 3 && ok; x++) {
                    for (int y = 0; y < 3; y++) {
                        int v = grid[i + x][j + y];
                        if (v < 1 || v > 9 || used[v]) {
                            ok = false;
                            break;
                        }
                        used[v] = true;
                    }
                }

                if (!ok) continue;

                int s = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];

                // Check rows
                for (int x = 0; x < 3; x++)
                    if (grid[i + x][j] + grid[i + x][j + 1] + grid[i + x][j + 2] != s)
                        ok = false;

                // Check columns
                for (int y = 0; y < 3; y++)
                    if (grid[i][j + y] + grid[i + 1][j + y] + grid[i + 2][j + y] != s)
                        ok = false;

                // Check diagonals
                if (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != s)
                    ok = false;

                if (grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] != s)
                    ok = false;

                if (ok) ans++;
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> grid = {
        {4, 3, 8, 4},
        {9, 5, 1, 9},
        {2, 7, 6, 2}
    };

    Solution sol;
    int result = sol.numMagicSquaresInside(grid);

    cout << "Number of magic squares: " << result << endl;

    return 0;
}
