//Problem Link: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/description
//Date: 03/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> xs, ys;
        for(auto &p : points) 
        {
            xs.push_back(p[0]);
            ys.push_back(p[1]);
        }

        // Coordinate compression
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        vector<pair<int,int>> comp(n);
        for(int i = 0; i < n; i++) 
        {
            int x = lower_bound(xs.begin(), xs.end(), points[i][0]) - xs.begin();
            int y = lower_bound(ys.begin(), ys.end(), points[i][1]) - ys.begin();
            comp[i] = {x, y};
        }

        int sizeX = xs.size();
        int sizeY = ys.size();

        // Grid to mark points
        vector<vector<int>> grid(sizeX, vector<int>(sizeY, 0));
        for(auto &p : comp) 
        {
            grid[p.first][p.second] = 1;
        }

        // 2D prefix sum
        vector<vector<int>> pre(sizeX+1, vector<int>(sizeY+1, 0));
        for(int i = 1; i <= sizeX; i++) 
        {
            for(int j = 1; j <= sizeY; j++) 
            {
                pre[i][j] = grid[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            }
        }

        // Query number of points inside rectangle
        auto query = [&](int x1,int y1,int x2,int y2) 
        {
            x1 = max(x1,0); y1 = max(y1,0);
            x2 = min(x2,sizeX-1); y2 = min(y2,sizeY-1);
            if(x1 > x2 || y1 > y2){
                return 0;
            } 
            x1++; y1++; x2++; y2++; // prefix sum is 1-indexed
            return pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1];
        };

        int ans = 0;

        for(int i = 0; i < n; i++) 
        {
            int Ax = comp[i].first, Ay = comp[i].second;

            for(int j = 0; j < n; j++) 
            {
                if(i == j){
                  continue;
                } 
                int Bx = comp[j].first, By = comp[j].second;

                if(Ax <= Bx && Ay >= By) 
                {
                    int inside = query(Ax, By, Bx, Ay);
                    if(inside == 2){
                      ans++; // Only Alice & Bob
                    } 
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{3,1},{1,3},{1,1}};
    cout << "Number of valid pairs: " << sol.numberOfPairs(points) << endl;
    return 0;
}
