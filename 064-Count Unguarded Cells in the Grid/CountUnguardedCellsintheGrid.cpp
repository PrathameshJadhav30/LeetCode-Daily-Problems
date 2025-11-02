//Problem Link: https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description
// Date: 2/11/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Depth First Search to mark guarded cells
    void dfs(int r, int c, string dir, vector<vector<int>>& vis, map<pair<int, int>, int>& mp) {
        int n = vis.size();
        int m = vis[0].size();
        // Out of bounds
        if (r < 0 || c < 0 || r >= n || c >= m) return;

        // Stop if wall or guard encountered
        if (mp.find({r, c}) != mp.end()) return;

        // Mark cell as guarded
        vis[r][c] = 1;

        // Continue in same direction
        if (dir == "r") dfs(r, c + 1, "r", vis, mp);
        if (dir == "l") dfs(r, c - 1, "l", vis, mp);
        if (dir == "u") dfs(r - 1, c, "u", vis, mp);
        if (dir == "d") dfs(r + 1, c, "d", vis, mp);
    }

    // Function to count unguarded cells
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vis(m, vector<int>(n, 0));  // visited matrix
        map<pair<int, int>, int> mp;                    // map to store walls & guards

        // Mark guards and walls
        for (auto it : guards) {
            mp[{it[0], it[1]}]++;
            vis[it[0]][it[1]] = 1;
        }
        for (auto it : walls) {
            mp[{it[0], it[1]}]++;
            vis[it[0]][it[1]] = 1;
        }

        // Perform DFS from each guard in all 4 directions
        for (auto it : guards) {
            int r = it[0];
            int c = it[1];
            dfs(r, c + 1, "r", vis, mp);
            dfs(r, c - 1, "l", vis, mp);
            dfs(r + 1, c, "d", vis, mp);
            dfs(r - 1, c, "u", vis, mp);
        }

        // Count unguarded cells
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    Solution obj;

    // Example Input
    int m = 4, n = 6;
    vector<vector<int>> guards = {{0, 0}, {1, 1}, {2, 3}};
    vector<vector<int>> walls = {{0, 1}, {2, 2}, {1, 4}};

    // Function Call
    int result = obj.countUnguarded(m, n, guards, walls);

    cout << "Number of unguarded cells: " << result << endl;

    return 0;
}
