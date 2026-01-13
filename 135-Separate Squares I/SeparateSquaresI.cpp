// Problem Link: https://leetcode.com/problems/separate-squares-i/description
// Date: 13/01/2026
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double L = 0.0, R = 1e9;
        double Ans = 0.0;

        // Binary search for 80 iterations for precision
        for (int it = 0; it < 80; it++) {
            double mid = L + (R - L) / 2.0;
            double LA = 0.0, UA = 0.0;

            for (int i = 0; i < (int)squares.size(); i++) {
                double y = squares[i][1];
                double l = squares[i][2];
                double TA = l * l;

                if (y + l <= mid) {
                    // Completely below
                    LA += TA;
                } 
                else if (y >= mid) {
                    // Completely above
                    UA += TA;
                } 
                else {
                    // Partially split
                    double below = (mid - y) * l;
                    LA += below;
                    UA += (TA - below);
                }
            }

            if (LA >= UA) {
                Ans = mid;
                R = mid;
            } else {
                L = mid;
            }
        }

        return Ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> squares(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> squares[i][0] >> squares[i][1] >> squares[i][2];
    }

    Solution sol;
    double result = sol.separateSquares(squares);

    cout << fixed << setprecision(6) << result << "\n";

    return 0;
}