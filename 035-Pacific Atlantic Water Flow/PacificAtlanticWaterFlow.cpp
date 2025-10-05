//Problem Link: https://leetcode.com/problems/pacific-atlantic-water-flow/description
//Date: 5/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // DFS for Pacific Ocean (top row and left column)
        for (int j = 0; j < n; j++) dfs(0, j, heights, pacific);
        for (int i = 0; i < m; i++) dfs(i, 0, heights, pacific);

        // DFS for Atlantic Ocean (bottom row and right column)
        for (int j = 0; j < n; j++) dfs(m - 1, j, heights, atlantic);
        for (int i = 0; i < m; i++) dfs(i, n - 1, heights, atlantic);

        // Find cells reachable by both oceans
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

private:
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        visited[i][j] = true;

        for (auto& d : directions) {
            int x = i + d[0], y = j + d[1];

            // Check boundaries and flow conditions
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if (visited[x][y]) continue;
            if (heights[x][y] < heights[i][j]) continue;

            dfs(x, y, heights, visited);
        }
    }
};

int main() {
    Solution sol;

    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };

    vector<vector<int>> result = sol.pacificAtlantic(heights);

    cout << "Cells that can flow to both oceans:\n";
    for (auto& cell : result) {
        cout << "[" << cell[0] << ", " << cell[1] << "]\n";
    }

    return 0;
}
