// Problem Link: https://leetcode.com/problems/separate-squares-ii/description
// Date: 15/01/2026
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <array>
#include <set>
#include <cmath>
#include <limits>

using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        auto maxSpan = [](vector<int>& bars) {
            int res = 1, streak = 1;
            for (int i = 1; i < bars.size(); i++) {
                if (bars[i] - bars[i - 1] == 1)
                    streak++;
                else
                    streak = 1;
                res = max(res, streak);
            }
            return res + 1;   // +1 because gaps form squares
        };

        int s = min(maxSpan(hBars), maxSpan(vBars));
        return s * s;
    }
};

int main() {
    Solution sol;

    // Example input
    int n = 5, m = 5;
    vector<int> hBars = {2, 3};
    vector<int> vBars = {1, 2, 3};

    int result = sol.maximizeSquareHoleArea(n, m, hBars, vBars);

    cout << "Maximum Square Hole Area: " << result << endl;

    return 0;
}
