//Problem Link: https://leetcode.com/problems/swim-in-rising-water/description
//Date: 06/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        // Min-heap storing {time, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        
        int ans = 0;
        
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int t = curr[0];
            int r = curr[1];
            int c = curr[2];
            
            ans = max(ans, t);
            
            // Reached destination
            if(r == n - 1 && c == n - 1)
                return ans;
            
            // Explore 4 directions
            for(auto& d : directions) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.push({grid[nr][nc], nr, nc});
                }
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> grid1 = {{0, 2}, {1, 3}};
    cout << "Output 1: " << sol.swimInWater(grid1) << endl;  // Expected: 3

    vector<vector<int>> grid2 = {
        {0, 1, 2, 3, 4},
        {24, 23, 22, 21, 5},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10, 9, 8, 7, 6}
    };
    cout << "Output 2: " << sol.swimInWater(grid2) << endl;  // Expected: 16
    
    return 0;
}
