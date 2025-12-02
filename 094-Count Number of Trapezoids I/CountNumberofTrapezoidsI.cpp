// Problem Link: https://leetcode.com/problems/count-number-of-trapezoids-i/description
// Date: 02/12/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int countTrapezoids(vector<vector<int>>& points) {
        const long long mod = 1e9 + 7;
        long long n = points.size();

        unordered_map<int, int> freq;
        freq.reserve(n);

        // Count occurrences of each y-coordinate
        for (auto& p : points)
            freq[p[1]]++;

        long long sum = 0, c2 = 0;

        for (auto& [y, f] : freq) {
            if (f <= 1) continue;

            long long c = f * (f - 1LL) / 2LL;  // choose 2 from f points
            sum += c;
            c2 += (c * c);
        }

        long long ans = sum * sum - c2;
        ans /= 2;
        ans %= mod;

        if (ans < 0) ans += mod;
        return ans;
    }
};

int main() {
    vector<vector<int>> points = {
        {1, 2},
        {3, 2},
        {5, 4},
        {7, 4},
        {9, 2},
        {11, 4}
    };

    int result = Solution::countTrapezoids(points);

    cout << "Number of trapezoids = " << result << endl;

    return 0;
}
