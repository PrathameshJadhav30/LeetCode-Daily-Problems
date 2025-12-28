// Problem Link: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description
// Date: 28/12/2025
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int i = m - 1; // last row
        int j = 0;     // first column
        int res = 0;

        while (i >= 0 && j < n) {
            if (grid[i][j] < 0) {
                res += n - j;  // all elements to the right are negative
                i--;
            } else {
                j++;
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> grid = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}
    };

    Solution obj;
    int result = obj.countNegatives(grid);

    cout << "Number of negative elements: " << result << endl;

    return 0;
}
