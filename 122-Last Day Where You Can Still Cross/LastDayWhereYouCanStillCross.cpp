// Problem Link: https://leetcode.com/problems/last-day-where-you-can-still-cross/description
// Date: 31/12/2025
#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

/*
 Disjoint Set Union (Union-Find)
*/
class DSU {
    vector<int> root;
    vector<int> size;

public:
    DSU(int n) : root(n), size(n, 1) {
        iota(root.begin(), root.end(), 0);
    }

    int find(int x) {
        if (root[x] != x)
            root[x] = find(root[x]); // path compression
        return root[x];
    }

    void unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);

        if (rx == ry) return;

        // union by size
        if (size[rx] > size[ry])
            swap(rx, ry);

        root[rx] = ry;
        size[ry] += size[rx];
    }
};

/*
 Solution Class
*/
class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        // +2 for virtual top (0) and bottom (row*col+1)
        DSU dsu(row * col + 2);

        vector<vector<int>> grid(row, vector<int>(col, 0));
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        // Process cells in reverse (flooding backward)
        for (int i = (int)cells.size() - 1; i >= 0; i--) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;

            grid[r][c] = 1; // land appears
            int id1 = r * col + c + 1;

            // connect neighbors
            for (auto &d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                    grid[nr][nc] == 1) {
                    int id2 = nr * col + nc + 1;
                    dsu.unite(id1, id2);
                }
            }

            // connect to virtual top
            if (r == 0)
                dsu.unite(0, id1);

            // connect to virtual bottom
            if (r == row - 1)
                dsu.unite(row * col + 1, id1);

            // check connectivity
            if (dsu.find(0) == dsu.find(row * col + 1))
                return i;
        }
        return -1;
    }
};

int main() {
    Solution sol;

    int row = 2;
    int col = 2;

    vector<vector<int>> cells = {
        {1,1},
        {2,1},
        {1,2},
        {2,2}
    };

    int result = sol.latestDayToCross(row, col, cells);

    cout << "Latest day to cross the grid: " << result << endl;

    return 0;
}