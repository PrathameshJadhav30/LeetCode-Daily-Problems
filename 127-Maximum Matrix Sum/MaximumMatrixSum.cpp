// Problem Link: https://leetcode.com/problems/maximum-matrix-sum/description
// Date: 05/01/2026
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;

        // Traverse matrix
        for (auto& row : matrix) {
            for (int val : row) {
                if (val < 0) negCount++;

                int absVal = abs(val);
                totalSum += absVal;
                minAbs = min(minAbs, absVal);
            }
        }

        // If negative count is even → all positives possible
        if (negCount % 2 == 0)
            return totalSum;

        // Else subtract twice the smallest absolute value
        return totalSum - 2LL * minAbs;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, -1},
        {-1, 1}
    };

    cout << "Maximum Matrix Sum: "
         << sol.maxMatrixSum(matrix) << endl;

    return 0;
}

