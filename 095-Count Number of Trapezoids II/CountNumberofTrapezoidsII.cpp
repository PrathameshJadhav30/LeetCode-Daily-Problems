// Problem Link: https://leetcode.com/problems/count-number-of-trapezoids-ii/description
// Date: 03/12/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, unordered_map<int, int>> t, v;

        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {

                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                // Normalize direction to avoid double counting
                if (dx < 0 || (dx == 0 && dy < 0))
                    dx = -dx, dy = -dy;

                int g = std::gcd(dx, abs(dy));

                int sx = dx / g;
                int sy = dy / g;

                // Line intercept key
                int des = sx * points[i][1] - sy * points[i][0];

                int key1 = (sx << 12) | (sy + 2000); // normalized slope key
                int key2 = (dx << 12) | (dy + 2000); // raw slope key

                ++t[key1][des];
                ++v[key2][des];
            }
        }
        return count(t) - count(v) / 2;
    }

    int count(unordered_map<int, unordered_map<int, int>>& mp) {
        long long ans = 0;

        for (auto& [k1, inner] : mp) {
            long long sum = 0;
            for (auto& [k2, val] : inner)
                sum += val;

            for (auto& [k2, val] : inner)
                ans += val * (sum -= val);
        }
        return ans;
    }
};


int main() {
    Solution sol;

    vector<vector<int>> points = {
        {0, 0}, {2, 0}, {1, 1}, {3, 1}, {4, 0}
    };

    cout << "Number of trapezoids: " 
         << sol.countTrapezoids(points) 
         << "\n";

    return 0;
}
