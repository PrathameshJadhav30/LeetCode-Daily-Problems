//Problem Link: https://leetcode.com/problems/set-intersection-size-at-least-two/description
// Date: 20/11/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](auto &x, auto &y) {
            if (x[1] == y[1]) 
                return x[0] > y[0];
            return x[1] < y[1];
        });

        int ans = 0;
        int a = -1, b = -1;

        for (auto &it : intervals) {
            int l = it[0], r = it[1];

            if (l > b) { 
                // Need 2 new elements
                a = r - 1;
                b = r;
                ans += 2;
            } 
            else if (l > a) { 
                // Need 1 new element
                a = b;
                b = r;
                ans += 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> intervals = {
        {1, 3},
        {3, 7},
        {2, 6},
        {2, 8}
    };

    int result = sol.intersectionSizeTwo(intervals);

    cout << "Minimum set size = " << result << endl;

    return 0;
}
