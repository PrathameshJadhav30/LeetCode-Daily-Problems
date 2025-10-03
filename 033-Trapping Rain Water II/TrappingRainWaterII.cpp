//Problem Link: https://leetcode.com/problems/trapping-rain-water-ii/description
//Date:3/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        // Min-heap (priority queue), stores {height, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Push all boundary cells into the heap
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n-1], i, n-1});
            visited[i][0] = true;
            visited[i][n-1] = true;
        }
        for (int j = 0; j < n; j++) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m-1][j], m-1, j});
            visited[0][j] = true;
            visited[m-1][j] = true;
        }

        int trappedWater = 0;
        vector<int> dir = {0, 1, 0, -1, 0};

        // BFS using min-heap
        while (!pq.empty()) {
            auto cell = pq.top();
            pq.pop();
            int height = cell[0];
            int x = cell[1], y = cell[2];

            // Explore neighbors
            for (int k = 0; k < 4; k++) {
                int nx = x + dir[k];
                int ny = y + dir[k+1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;

                    // If neighbor is lower, trap water
                    trappedWater += max(0, height - heightMap[nx][ny]);

                    // Push the max(height, neighborHeight) into heap
                    pq.push({max(height, heightMap[nx][ny]), nx, ny});
                }
            }
        }

        return trappedWater;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> heightMap1 = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    vector<vector<int>> heightMap2 = {{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}};

    cout << sol.trapRainWater(heightMap1) << endl; // Output: 4
    cout << sol.trapRainWater(heightMap2) << endl; // Output: 10
    return 0;
}
