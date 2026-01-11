// Problem Link: https://leetcode.com/problems/maximal-rectangle/description
// Date: 11/01/2026
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int M = matrix.size();
        int N = matrix[0].size();

        // Convert char matrix to int matrix
        vector<vector<int>> mat(M, vector<int>(N));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                mat[i][j] = matrix[i][j] - '0';
            }
        }

        // Row-wise prefix width calculation
        for (int i = 0; i < M; i++) {
            for (int j = 1; j < N; j++) {
                if (mat[i][j] == 1) {
                    mat[i][j] += mat[i][j - 1];
                }
            }
        }

        int Ans = 0;

        // Fix each column
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < M; i++) {
                int width = mat[i][j];
                if (width == 0) continue;

                // Expand downward
                int currWidth = width;
                for (int k = i; k < M && mat[k][j] > 0; k++) {
                    currWidth = min(currWidth, mat[k][j]);
                    int height = k - i + 1;
                    Ans = max(Ans, currWidth * height);
                }

                // Expand upward
                currWidth = width;
                for (int k = i; k >= 0 && mat[k][j] > 0; k--) {
                    currWidth = min(currWidth, mat[k][j]);
                    int height = i - k + 1;
                    Ans = max(Ans, currWidth * height);
                }
            }
        }

        return Ans;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    cout << "Maximal Rectangle Area: "
         << sol.maximalRectangle(matrix) << endl;

    return 0;
}